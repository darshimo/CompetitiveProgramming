#include <cstdio>

int main(void)
{
  int n, k;
  scanf("%d %d", &n, &k);
  if (k > (n - 1) * (n - 2) / 2)
  {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", n * (n - 1) / 2 - k);
  for (int i = 1; i < n; i++)
  {
    printf("%d %d\n", i, n);
  }
  int cnt = (n - 1) * (n - 2) / 2;
  for (int i = 1; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (cnt <= k)
        break;
      cnt--;
      printf("%d %d\n", i, j);
    }
  }

  return 0;
}
