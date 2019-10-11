#include <cstdio>

int main(void){
    int n,m,t[100],p,x,ans[100];
    int sum=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",t+i);
        sum+=t[i];
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&p,&x);
        ans[i] = sum - t[p-1] + x;
    }

    for(int i=0;i<m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
