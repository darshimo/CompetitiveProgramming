#include <cstdio>

int main(){
    int i,j,n,m,c,ret,sum,tmp;
    int b[20];
    scanf("%d %d %d",&n,&m,&c);
    for(i=0;i<m;i++){
        scanf("%d",b+i);
    }
    ret = 0;
    for(i=0;i<n;i++){
        sum = c;
        for(j=0;j<m;j++){
            scanf("%d",&tmp);
            sum += tmp*b[j];
        }
        if(sum>0)ret++;
    }
    printf("%d\n",ret);
    return 0;
}
