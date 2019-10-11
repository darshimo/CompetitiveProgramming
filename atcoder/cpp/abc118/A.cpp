#include <cstdio>

int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    if(b%a)printf("%d\n",b-a);
    else printf("%d\n",b+a);
    return 0;
}
