#include <cstdio>
#include <algorithm>

int main(void){
    int i,n,tmp,sum=0;
    int v[20];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",v+i);
    }
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        sum+=std::max(0,v[i]-tmp);
    }
    printf("%d\n",sum);
    return 0;
}
