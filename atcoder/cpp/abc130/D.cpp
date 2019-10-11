#include <cstdio>

int a[100000];
int n;
long int k;

int func(int l, int r, long int *sum){
    if(*sum>=k)return r;
    int j;
    for(j=r+1;j<n;j++){
        *sum += a[j];
        if(*sum>=k)break;
    }
    return j;
}

int main(void){
    scanf("%d %ld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }

    int tmp;
    int j=-1;
    long int sum = 0;
    long int ans = 0;
    for(int i=0;i<n;i++){
        j = func(i,j,&sum);
        if(j>=n)break;
        ans += n-j;
        sum -= a[i];
    }

    printf("%ld\n",ans);

    return 0;
}
