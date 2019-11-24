#include <stdio.h>

char s[100];
int pos;

void reverse(char temp[], int tempos)
{
  if(temp[tempos] == '\0')
    {
      return;
    }

  reverse(temp, tempos + 1);

  s[pos++] = temp[tempos];
}


int main(void)
{
  reverse("hola", 0);
  s[pos] = '\0';
  printf("%s\n", s);
  return 0;
}
