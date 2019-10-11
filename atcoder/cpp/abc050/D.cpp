#include <cstdio>
#include <climits>
#include <cmath>

int bit_count(unsigned long long int n, int m){
    int count = 0;
    for(;m>0;m--){
        count += n%2;
        n/=2;
    }
    return count;
}

int bit_range(unsigned long long int n){
    int count=0;
    while(true){
        if(n<(unsigned long long int)(pow(2,count)))break;
        count++;
    }
    return count;
}

int main(void){
    unsigned long long int u,n,ans,u_inverse,count=0,tmp;
    scanf("%lld",&n);
    for(u=0;u<=n;u++){
        printf("%llu\n",u);
        u_inverse=(~u)*2;
        count += (unsigned long long int)(pow(2,bit_count(u_inverse,bit_range(n-u))))%1000000007;
        count %= 1000000007;
    }
    printf("%llu\n",count);
    printf("%x\n",ULLONG_MAX);
    return 0;
}
