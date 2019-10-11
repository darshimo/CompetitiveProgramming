#include <cstdio>

int main(void)
{
  int n, a, b, c, d;
  scanf("%d", &n);
  a = (n / 1000) % 10;
  b = (n / 100) % 10;
  c = (n / 10) % 10;
  d = n % 10;
  if (a == b || b == c || c == d)
    printf("Bad\n");
  else
    printf("Good\n");
  return 0;
}