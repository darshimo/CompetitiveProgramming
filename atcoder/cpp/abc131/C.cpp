#include <cstdio>

unsigned long long int cnt(unsigned long long int a, unsigned long long int b, unsigned long long int c)
{
  return b / c - a / c;
}

unsigned long long int lcm(unsigned long long int a, unsigned long long int b)
{
  unsigned long long int x, tmp, r;

  x = a * b;
  if (a < b)
  {
    tmp = a;
    a = b;
    b = tmp;
  }

  r = a % b;
  while (r != 0)
  {
    a = b;
    b = r;
    r = a % b;
  }

  return x / b;
}

int main(void)
{
  unsigned long long int a, b, c, d;
  scanf("%llu %llu %llu %llu", &a, &b, &c, &d);
  printf("%llu\n", b - a + 1 - cnt(a - 1, b, c) - cnt(a - 1, b, d) + cnt(a - 1, b, lcm(c, d)));
  return 0;
}
