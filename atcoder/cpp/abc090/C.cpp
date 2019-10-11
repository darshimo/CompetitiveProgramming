#include <stdio.h>
#include <stdlib.h>

int main(){
    long long int n,m,ans;
    scanf("%llu %llu",&n,&m);
    ans = abs(m-2)*abs(n-2);
    printf("%llu\n",ans);
    return 0;
}
