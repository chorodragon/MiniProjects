#include <stdio.h>
#include <string.h>

#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}

int main()
{
  swap(int, 3, 4);
  return 0;
}
