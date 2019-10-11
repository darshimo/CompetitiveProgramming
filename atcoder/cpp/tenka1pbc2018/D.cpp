#include <cstdio>
#include <cmath>

void rekkyo(int i, int k, int n){
    int j;
    for(j=(i+1)*i/2;j>i*(i-1)/2;j--){
        printf(" %d",j);
    }
    j=i*(i-1)/2+i+1;
    if(j<=n)printf(" %d",j);
    int tmp = i+2;
    while(true){
        j+=tmp;
        if(j>n)break;
        printf(" %d",j);
        tmp++;
    }
    printf("\n");
    return;
}

int main(){
    int i,k,n;
    scanf("%d",&n);
    k = sqrt(n*2)+1;
    if(n!=k*(k-1)/2){
        printf("No\n");
        return 0;
    }
    printf("Yes\n%d\n",k);

    for(i=0;i<k;i++){
        printf("%d",k-1);
        rekkyo(i,k,n);
    }

    return 0;
}
