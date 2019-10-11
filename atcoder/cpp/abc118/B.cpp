#include <cstdio>

int main(void){
    int i,j,k,n,m,a,ans;
    int hoge[30];
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)hoge[i]=0;
    for(i=0;i<n;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d",&a);
            hoge[a-1]++;
        }
    }
    ans = 0;
    for(i=0;i<m;i++){
        if(hoge[i]==n)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
