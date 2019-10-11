#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
    int i,n;
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",a+i);

    sort(a,a+n);

    long long int ans = 0;
    int m = n/2;
    if(n%2){
        long long int tmp1,tmp2;
        tmp1 = 2*a[m+1]-a[m]-a[m-1];
        tmp2 = a[m+1]+a[m]-2*a[m-1];

        for(i=0;i<m-1;i++){
            ans-=a[i]*2;
        }
        for(i=m+2;i<n;i++){
            ans+=a[i]*2;
        }
        ans+=max(tmp1,tmp2);
    }else{
        for(i=0;i<m-1;i++){
            ans-=a[i]*2;
        }
        ans-=a[m-1];
        ans+=a[m];
        for(i=m+1;i<n;i++){
            ans+=a[i]*2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
