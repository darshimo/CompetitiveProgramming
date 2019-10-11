#include <stdio.h>
#include <algorithm>

int main(void){
    long long int n,a,b,c,d,e,m;
    scanf("%lld",&n);
    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&c);
    scanf("%lld",&d);
    scanf("%lld",&e);
    m = std::min(std::min(std::min(a,b),std::min(c,d)),e);
    printf("%lld\n",(n-1)/m+5);
    return 0;
}
