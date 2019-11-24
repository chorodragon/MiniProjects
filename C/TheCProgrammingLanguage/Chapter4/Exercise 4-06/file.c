#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP    100
#define NUMBER   '0'
#define ALPHA    'a'
#define MAXVAL   100 //maximum depth of val stack
#define BUFSIZE  100 //maximum size of the buffer
#define MAXVAR   26  //maximum number of variables

int     varp = 0;               // next variable position
int	sp   = 0;		// next free stack position
double	val[MAXVAL];		// value stack
char	buf[BUFSIZE];		// buffer for ungetch
int	bufp = 0;		// next free position in buf
char	vars[MAXVAR];

int	getop(char []);
void	push(double);
double	pop(void);
int	getch(void);
void	ungetch(int);
double	stackTop(void);
void	reverseTop(void);
void	clearStack(void);
char	addVariable(double);
double	returnVariable(char []);

int main()
{
  int type;
  double op2;
  double op1;
  char s[MAXOP];

  for (int i = 0; i < MAXVAR; i++)
    vars[i] = 0.0;
  
  while((type = getop(s)) != EOF)
    {
      switch(type)
	{
	case NUMBER:
	  push(atof(s));
	  break;
	case ALPHA:
	  push(returnVariable(s));
	  break;
	case '+':
	  push(pop() + pop());
	  break;
	case '-':
	  op2 = pop();
	  push(pop() - op2);
	  break;
	case '*':
	  push(pop() * pop());
	  break;
	case '/':
	  op2 = pop();
	  if(op2 != 0.0)
	    {
	      push(pop() / op2);
	    }
	  else
	    {
	      printf("error: zero division\n");
	    }
	  break;
	case '%':
	  op2 = pop();
	  if (op2 != 0.0)
	    {
	      double temp = fmod(pop(), op2);
	      push(temp);
	    }
	  else
	    {
	      printf("error: zero division\n");
	    }
	  break;
	case '\n':
	  op1 = pop();
	  printf("%c\t%.8g\n", addVariable(op1), op1);
	  break;
	case 'p':
	  printf("stack top: %g\n", stackTop());
	  break;
	case 'r':
	  reverseTop();
	  break;
	case 'c':
	  clearStack();
	  break;
	case 's':
	  push(sin(pop()));
	  break;
	case 'e':
	  push(exp(pop()));
	  break;
	case '^':
	  op2 = pop();
	  push(pow(pop(), op2));
	  break;
	default:
	  printf("error: unknown command %s\n", s);
	  break;
	}
    }
  return 0;
}

int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  i = 0;

  if(c == '-')
    {
      s[++i] = c = getch();
    }
  
  if(!isdigit(c) && c != '.' && !isalpha(c))
    {
      if(s[i-1] == '-')
	{
	  ungetch(c);
	  return s[i-1];
	}
      else
	{
	  return c;
	}
    }

  if (isalpha(c))
    {
      return ALPHA;
    }
  
  if (isdigit(c))
    {
      while (isdigit(s[++i] = c = getch()))
	;
    }

  if (c == '.')
    {
      while (isdigit(s[++i] = c = getch()))
	;
    }

  s[i] = '\0';

  if (c != EOF)
    {
      ungetch(c);
    }
  return NUMBER;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    {
      printf("error: too many characters on buffer\n");
    }
  else
    {
      buf[bufp++] = c;
    }
}

void push(double f)
{
  if(sp < MAXVAL)
    {
      val[sp++] = f;
    }
  else
    {
      printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
  if (sp > 0)
    {
      return val[--sp];
    }
  else
    {
      printf("error: stack is empty\n");
      return 0.0;
    }
}

double stackTop(void) {
  if (sp > 0)
    {
      return val[sp - 1];
    }
  else
    {
      printf ("error: stack is empty\n");
      return 0.0;
    }
}

void reverseTop(void) {

  double op1;
  
  if (sp > 1)
    {
      op1 = val[sp - 1];
      val[sp - 1] = val[sp - 2];
      val[sp - 2] = op1;
    }
  else
    {
      printf("error: stack size isn't enough to do this operation\n");
    }
}

void clearStack(void) {
  sp = 0;
  printf("info: stack cleared\n");
}

char addVariable(double value)
{
  char varName = 97;
  if (varp >= MAXVAR)
    {
      sp = 0;
    }
  vars[sp] = value;
  
  varName += sp++;
  return varName;
}

double returnVariable(char var[])
{
  double value = 0.0;
  char c = tolower(var[0]);
  value = vars[c - 97];
  
  return value;
}
