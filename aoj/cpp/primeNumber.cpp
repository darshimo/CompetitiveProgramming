#include <cstdio>
#include <cmath>

bool isPrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){
    int i,n,x;
    int c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(isPrime(x))c++;
    }
    printf("%d\n",c);
    return 0;
}
