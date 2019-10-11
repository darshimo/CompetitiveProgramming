#include <cstdio>
#include <queue>
using namespace std;

typedef struct{
    int node;
    int weight;
}nw;

bool check[100001];
queue<nw> q[100001];
bool isblack[100001];

void coloring(int n, bool color){
    if(check[n])return;
    //printf("node:%d\n",n);

    check[n] = true;
    isblack[n] = color;

    nw tmp;
    while(!q[n].empty()){
        tmp = q[n].front();
        q[n].pop();
        if(tmp.weight%2==1){
            //printf("u:%d,v:%d,w:%d,->reverse\n",n,tmp.node,tmp.weight);
            coloring(tmp.node,!color);
        }else{
            //printf("u:%d,v:%d,w:%d,->same\n",n,tmp.node,tmp.weight);
            coloring(tmp.node,color);
        }
    }
    return;
}

int main(void){
    int n,u,v,w;
    for(int i=1;i<=n;i++){
        check[i] = false;
    }
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        nw tmp;
        tmp.node = v;
        tmp.weight = w;
        q[u].push(tmp);
        tmp.node = u;
        tmp.weight = w;
        q[v].push(tmp);
    }
    coloring(1,true);
    for(int i=1;i<=n;i++){
        if(isblack[i])printf("1\n");
        else printf("0\n");
    }
    return 0;
}
