#include <cstdio>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;
  int t1, t2;
  scanf("%d", &n);
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &t1, &t2);
    v[i] = make_pair(t2, t1);
  }

  sort(v.begin(), v.end());

  int sum = 0;
  int i = 0;
  for (; i < n; i++)
  {
    sum += v[i].second;
    if (sum > v[i].first)
      break;
  }

  if (i == n)
    printf("Yes\n");
  else
    printf("No");

  return 0;
}
