#include <cstdio>

int main(void){
    long long int w,h,x,y;
    scanf("%lld %lld %lld %lld",&w,&h,&x,&y);
    printf("%lld",(w*h)/2);
    if((w%2==1)&&(h%2==1))printf(".5");

    if((2*x==w)&&(2*y==h))printf(" 1\n");
    else printf(" 0\n");
    return 0;
}
