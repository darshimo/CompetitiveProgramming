#include <cstdio>
#include <vector>
using namespace std;

typedef struct{
    int id;
    int height;
}data;

bool check[2][100000];
vector<int> a[100000];
int d[100000][100000];

data func(int u, int c){
    check[c][u] = true;

    int i,v;
    int id;
    int height = -1;
    data tmp;

    for(i=0;i<a[u].size();i++){
        v = a[u][i];
        if(check[c][v])continue;
        tmp = func(v,c);
        if(tmp.height + d[u][v] > height){
            id = tmp.id;
            height = tmp.height + d[u][v];
        }
    }

    if(height < 0){
        tmp.id = u;
        tmp.height = 0;
    }else{
        tmp.id = id;
        tmp.height = height;
    }
    return tmp;
}

int main(){
    int i,n,s,t,w;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        check[0][i] = false;
        check[1][i] = false;
    }
    for(i=1;i<n;i++){
        scanf("%d %d %d",&s,&t,&w);
        a[s].push_back(t);
        a[t].push_back(s);
        d[s][t] = w;
        d[t][s] = w;
    }

    data tmp;
    tmp = func(0,0);
    tmp = func(tmp.id,1);

    printf("%d\n",tmp.height);

    return 0;
}
