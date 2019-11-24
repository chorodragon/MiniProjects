#include <stdio.h> 

char s[100];
int pos;

void printd(int n)
{
  if (n < 0)
    {
      s[pos++] = '-';
      n = -n;
    }
  if (n / 10)
    {
      printd(n / 10);
    }
  s[pos++] = (n % 10 + '0');
}

int main(void)
{
  pos = 0;
  printd(-140);
  s[pos] = '\0';
  printf("%s\n", s);
  return 0;
}
