#include <cstdio>

int main(void)
{
  int n, l;
  scanf("%d %d", &n, &l);
  if (l > 0)
    printf("%d\n", l * (n - 1) + n * (n - 1) / 2);
  else if (l + n - 1 < 0)
    printf("%d\n", (l - 1) * (n - 1) + n * (n - 1) / 2);
  else
    printf("%d\n", l * n + n * (n - 1) / 2);
  return 0;
}
