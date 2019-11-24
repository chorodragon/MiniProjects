#include <errno.h>
#include <ctype.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>

#define CTRL_KEY(k) ((k) & 0x1f)
#define KILO_VERSION "0.0.1"

struct editorConfig {
  struct termios orig_termios; //Original attributes
  int screenrows; //Amount of terminal rows
  int screencols; //Amount of terminal columns
  int cx, cy;
};

struct abuf {
  char *b;
  int len;
};

enum editorKey {
  ARROW_LEFT = 1000,
  ARROW_RIGHT, 
  ARROW_UP,
  ARROW_DOWN,
  PAGE_UP,
  PAGE_DOWN,
  HOME_KEY,
  END_KEY,
  DEL_KEY
};

#define ABUF_INIT {NULL, 0}

struct editorConfig E; //Global structure

void editorMoveCursor(int key){
  switch(key){
    case ARROW_LEFT:
      if (E.cx != 0)
        E.cx--;
      break;
    case ARROW_RIGHT:
      if (E.cx != E.screencols - 1)
        E.cx++;
      break;
    case ARROW_UP:
      if (E.cy != 0)
        E.cy--;
      break;
    case ARROW_DOWN:
      if (E.cy != E.screenrows - 1)
        E.cy++;
      break;
  }
}

void abAppend(struct abuf *ab, const char *s, int len){
  char *new = realloc(ab->b, ab->len + len);

  if (new == NULL)
    return;

  memcpy(&new[ab->len], s, len);
  ab->b = new;
  ab->len += len;
}

void abFree(struct abuf *ab){
  free(ab->b);
}

int getWindowSize(int *rows, int *cols){
  struct winsize ws;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0){
    return -1;
  } else {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return 0;
  }

}

void die(const char *s)
{  
  write(STDOUT_FILENO, "\x1b[2J", 4);
  write(STDOUT_FILENO, "\x1b[H", 3);
  perror(s); //Show a descriptive error message to stderr
  exit(1); //Exit program with error (Code '1')
}

void disableRawMode()
{
  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1) //Load original attributes to terminal
    die("tcsetattr");
}

void enableRawMode()
{
  struct termios raw;
  if(tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) //Store original attributes
    die("tcgetattr");
  
  atexit(disableRawMode); //Before program ends its execution call disableRawMode function
  raw = E.orig_termios;

  //Types of flags:
  //c_lflag: local flags
  //i_iflag: input flags
  //c_oflag: output flags
  //c_cflag: control flags
  //Flags:
  //ECHO: prints every key pressed to the terminal
  //ICANON: when enabled read-by-line, otherwise read-by-byte
  //ISIG: enable SIGINT and SIGTSTP
  //IXON: enable CTRL-S(XOFF) and CTRL-q(XON)
  //IEXTEN: enable CTRL-V
  //ICRNL: enable CTRL-M (new line '\n')
  //OPOST: enable input processing (newline, carriage return, etc...)
  //BRKINT, INPCK, ISTRIP, CS8: doesn't have an observable effect
  raw.c_iflag &= ~(IXON | ICRNL | ISTRIP | INPCK | BRKINT); 
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag &= ~(CS8);

  //VMIN: set the minimum amount of bytes before read function can return
  //VTIME: set the amount of time to wait before read returns, it's in tenths of seconds
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;

  //TCSAFLUSH specifies when to apply the change
  //In this case, it waits for all pending output to be written to the terminal, and also discards any input that hasn’t been read
  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) //Set new attributes
    die("tcsetattr");
}

int editorReadKey()
{
  int nread;
  char c;
  // Read function return the numbers of bytes read, and returns 0 when it reaches the end of the input or file.
  // The return of the function Read is stored on the 'nread' variable
  while((nread = read(STDIN_FILENO, &c, 1)) != 1) // Read function reads from the standard input 1 byte of data and stores it on the variable 'c'
    {
      if(nread == -1 && errno !=EAGAIN) // In case Read function produces an error the program ends its execution, calling the die function before
	die("read");
    }

  if (c == '\x1b'){
    char seq[3];

    if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
    if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';

    if (seq[0] == '['){
      if (seq[1] >= '0' && seq[1] <= '9'){
        if (read(STDIN_FILENO, &seq[2], 1) != -1)
          return '\x1b';
        if (seq[2] == '~'){
          switch(seq[1]){
            case '1': return HOME_KEY;
            case '3': return DEL_KEY;
            case '4': return END_KEY;
            case '5': return PAGE_UP;
            case '6': return PAGE_DOWN;
            case '7': return HOME_KEY;
            case '8': return END_KEY;
          }
        }
      } else {
        switch (seq[1]){
          case 'A': return ARROW_UP;
          case 'B': return ARROW_DOWN;
          case 'C': return ARROW_RIGHT;
          case 'D': return ARROW_LEFT;
          case 'H': return HOME_KEY;
          case 'F': return END_KEY;
        }
      } else if (seq[0] == 'O'){
        switch (seq[1]){
          case 'H': return HOME_KEY;
          case 'F': return END_KEY;
        }
      }
    }
    return '\x1b';
  } else {
    return c;
  }
}

//Draw the rows
void editorDrawRows(struct abuf *ab){
  int y;
  for (y = 0; y < E.screenrows; y++){
    if (y == E.screenrows / 3){
      char welcome[80];
      int welcomelen = snprintf(welcome, sizeof(welcome),
          "Kilo Editor -- version %s", KILO_VERSION);
      if (welcomelen > E.screencols)
        welcomelen = E.screencols;
      int padding = (E.screencols - welcomelen) / 2;
      if (padding) {
        abAppend(ab, "~", 1);
        padding--;
      }
      while (padding--) 
        abAppend(ab, " ", 1);
      abAppend(ab, welcome, welcomelen);
    } else {
      abAppend(ab, "~", 1);
    }

    abAppend(ab, "\x1b[K", 3); //Clear Line

    if (y < E.screenrows - 1){
      abAppend(ab, "\r\n", 2);
    }
  }
}

//Refresh screen
void editorRefreshScreen(){
  struct abuf ab = ABUF_INIT;
  abAppend(&ab, "\x1b[?25l", 6); //Hide Cursor
  //abAppend(&ab, "\x1b[2J", 4); Clear all the screen
  abAppend(&ab, "\x1b[H", 3); //Puts the cursor in the first row and first column

  editorDrawRows(&ab);

  char buf[32];
  snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);

  abAppend(&ab, buf, strlen(buf)); //Puts the cursor 
  abAppend(&ab, "\x1b[?25h", 6); //Show Cursor
  write(STDOUT_FILENO, ab.b, ab.len);
  abFree(&ab);
}

// Process user input byte by byte
void editorProcessKeypress()
{
  int c = editorReadKey(); //Call to editorReadKey function

  switch(c)
    {
    case CTRL_KEY('q'): //In case user presses Control key + 'q' the program ends its execution
      write(STDOUT_FILENO, "\x1b[2J", 4);
      write(STDOUT_FILENO, "\x1b[H", 3);
      exit(0);
      break;
    case ARROW_LEFT:
    case ARROW_RIGHT:
    case ARROW_UP:
    case ARROW_DOWN:
      editorMoveCursor(c);
      break;
    }
}

void initEditor(){
  E.cx = 0;
  E.cy = 0;

  if (getWindowSize(&E.screenrows, &E.screencols) == -1)
    die("getWindowSize");
}

// Main Function
int main()
{
  enableRawMode(); //Enable raw input mode
  initEditor();
  editorRefreshScreen();

  while(1)
    {
      editorRefreshScreen();
      editorProcessKeypress(); //Process user input until the program ends its execution
    }
  return 0;
}
