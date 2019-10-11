#include <cstdio>
#include <cstdlib>
#include <vector>
#include <numeric>

int gcd(int x, int y){
    if(y%x)return gcd(y%x,x);
    return x;
}

int main(){
    int i,n;
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    if(a[0]==1)a[n-1]=1;
    else {
        for(i=1;i<n;i++){
            if(a[i-1]<a[i])a[i]=gcd(a[i-1],a[i]);
            else a[i]=gcd(a[i],a[i-1]);
        }
    }
    printf("%d\n",a[n-1]);
    return 0;
}
