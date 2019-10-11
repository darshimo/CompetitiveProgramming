#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[100000];
bool check[100000];
int low[100000];
int num[100000];
bool isPoint[100000];

int func(int u, int n){
    if(check[u])return n;

    num[u] = n;
    n++;
    check[u] = true;
    int i;
    int tmp1 = num[u];
    int tmp2;
    for(i=0;i<a[u].size();i++){
        tmp2 = a[u][i];
        if(check[tmp2]){
            tmp1 = min(tmp1,num[tmp2]);
        }else{
            n = func(tmp2,n);
            tmp1 = min(tmp1,low[tmp2]);
            if(low[tmp2]>=num[u])isPoint[u] = true;
        }
    }

    low[u] = tmp1;

    return n;
}

int func0(int u, int n){
    if(check[u])return n;

    num[u] = n;
    n++;
    check[u] = true;
    int i;
    int tmp = 0;
    int tmp1 = num[u];
    int tmp2;
    for(i=0;i<a[u].size();i++){
        tmp2 = a[u][i];
        if(check[tmp2]){
            tmp1 = min(tmp1,num[tmp2]);
        }else{
            tmp++;
            n = func(tmp2,n);
            tmp1 = min(tmp1,low[tmp2]);
            if(low[tmp2]>=num[u])isPoint[u] = true;
        }
    }

    low[u] = tmp1;

    if(tmp<2)isPoint[u] = false;

    return n;
}

int main(){
    int i,s,t,V,E;

    scanf("%d %d",&V,&E);

    for(i=0;i<V;i++){
        check[i] = false;
        isPoint[i] = false;
    }
    for(i=0;i<E;i++){
        scanf("%d %d",&s,&t);
        a[s].push_back(t);
        a[t].push_back(s);
    }

    func0(0,1);

    for(i=0;i<V;i++)if(isPoint[i])printf("%d\n",i);

    return 0;
}
