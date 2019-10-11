#include <cstdio>
#include <vector>
using namespace std;

typedef long long int lli;

bool check[100000];

lli permu(lli n, lli r)
{
  lli ans = 1;
  for (int i = 0; i < r; i++)
  {
    ans = (ans * n) % 1000000007;
    n--;
  }
  return ans;
}

lli cnt_sb(vector<lli> *v, lli p, lli k)
{
  if (check[p])
  {
    return 1;
  }

  check[p] = true;
  lli ans = permu(k - 2, v[p].size() - 1);
  for (int i = 0; i < v[p].size(); i++)
  {
    lli u = v[p][i];
    ans = (ans * cnt_sb(v, u, k)) % 1000000007;
  }

  return ans;
}

lli cnt(vector<lli> *v, lli k)
{
  check[0] = true;
  lli ans = (k * permu(k - 1, v[0].size())) % 1000000007;
  for (int i = 0; i < v[0].size(); i++)
  {
    lli u = v[0][i];
    ans = (ans * cnt_sb(v, u, k)) % 1000000007;
  }
  return ans;
}

int main(void)
{
  lli n, k, a, b;
  vector<lli> v[100000];
  scanf("%llu %llu", &n, &k);
  for (int i = 0; i < n; i++)
  {
    check[i] = false;
  }

  for (int i = 0; i < n - 1; i++)
  {
    scanf("%llu %llu", &a, &b);
    v[a - 1].push_back(b - 1);
    v[b - 1].push_back(a - 1);
  }

  printf("%lld\n", cnt(v, k));

  return 0;
}
