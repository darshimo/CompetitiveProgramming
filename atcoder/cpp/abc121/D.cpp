#include <cstdio>

long int fun2(long int n){
    long int b=4;
    for(;;){
        if(2*b>n)break;
        b*=2;
    }
    return b;
}

long int fun(long int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 3;
    if(n==3)return 0;
    long int b = fun2(n);
    return b*((n-b+1)%2)+fun(n-b);
}

int main(){
    long int a,b;
    scanf("%ld %ld",&a,&b);
    if(a>b){printf("error\n");return 1;}
    if(a==0){a=1;}
    printf("%ld\n",fun(a-1)^fun(b));
    return 0;
}
