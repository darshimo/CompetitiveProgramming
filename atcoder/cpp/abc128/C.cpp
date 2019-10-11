#include <cstdio>

int n,m,k,p[11];
bool s[11][11];

int solve(int sn){
    if(sn>n){
        int i;
        for(i=1;i<=m;i++){
            if(p[i]==false)break;
        }
        if(i==m+1)return 1;
        else return 0;
    }

    int cnt=0;

    cnt += solve(sn+1);

    for(int i=1;i<=m;i++){
        if(s[i][sn])p[i]=!p[i];
    }
    cnt += solve(sn+1);
    for(int i=1;i<=m;i++){
        if(s[i][sn])p[i]=!p[i];
    }
    return cnt;
}

int main(void){
    int tmp;

    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            s[i][j] = false;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&tmp);
            s[i][tmp] = true;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&tmp);
        p[i] = (tmp==0);
    }

    printf("%d\n",solve(1));

    return 0;
}
