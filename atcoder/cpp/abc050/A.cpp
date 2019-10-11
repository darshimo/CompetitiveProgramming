#include <cstdio>

int main(void){
    int a,b;
    char c;
    scanf("%d %c %d",&a,&c,&b);
    if(c=='+')printf("%d\n",a+b);
    else printf("%d\n",a-b);
    return 0;
}
