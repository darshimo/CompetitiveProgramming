#include <cstdio>

typedef struct{
    int father;
}data;

data d[100001];

bool check(int x, int y){
    int tmpx = x;
    int tmpy = y;
    bool bx=false,by=false;
    while(true){
        if(d[x].father==0)break;
        bx = true;
        x = d[x].father;
    }
    while(true){
        if(d[y].father==0)break;
        by = true;
        y = d[y].father;
    }
    if(x==y)return false;
    d[x].father = y;
    if(bx)d[tmpx].father = y;
    if(by)d[tmpy].father = y;
    return true;
}

int main(void){
    int n,m,x,y,z;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        d[i].father = 0;
    }
    int ans = n;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&z);
        if(check(x,y))ans--;
    }
    printf("%d\n",ans);
    return 0;
}
