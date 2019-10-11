#include <stdio.h>
#include <algorithm>

int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a==b)printf("%d\n",2*a);
    else printf("%d\n",std::max(a,b)*2-1);
    return 0;
}
