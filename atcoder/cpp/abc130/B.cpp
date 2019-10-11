#include <cstdio>

int main(void){
    int n,x;
    scanf("%d %d",&n,&x);
    int l;
    int d=0;
    int ans=1;
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&l);
        d+=l;
        if(x<d)break;
    }
    for(int j=0;j<n-i;j++){
        scanf("%d",&l);
    }
    printf("%d\n",i);
    return 0;
}
