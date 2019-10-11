#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct{
    int height;
    int max;
}data;

int *check;
vector<int> a[100000];
int **d;

data func(int u){//return height and max
    check[u] = true;

    int i,v,h1,h2,max,tmph,tmpmax;
    h1 = 0;
    h2 = 0;
    max = 0;
    data tmp;
    for(i=0;i<a[u].size();i++){
        v = a[u][i];
        if(check[v])continue;
        tmp = func(v);
        tmph = tmp.height + d[u][v];
        tmpmax = tmp.max;

        if(tmph>h1){
            h2 = h1;
            h1 = tmph;
        }else if(tmph>h2){
            h2 = tmph;
        }

        if(tmpmax>max)max = tmpmax;
    }

    if(h1+h2>max)max = h1+h2;

    data ret;
    ret.height = h1;
    ret.max = max;
    return ret;
}

int main(){
    int i,n,s,t,w;

    scanf("%d",&n);
    check = (int *)malloc(sizeof(int)*n);
    d = (int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++){
        d[i] = (int *)malloc(sizeof(int)*n);
        check[i] = false;
    }

    for(i=1;i<n;i++){
        scanf("%d %d %d",&s,&t,&w);
        a[s].push_back(t);
        a[t].push_back(s);
        d[s][t] = w;
        d[t][s] = w;
    }

    data tmp = func(0);
    printf("%d\n",tmp.max);

    return 0;
}
