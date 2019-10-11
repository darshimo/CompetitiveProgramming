#include <stdio.h>

int main(){
    int a,b,c;
    c=0;
    scanf("%d %d",&a,&b);
    for(int i=a;i<b+1;i++){
        if((i/10000)!=(i%10))continue;
        if(((i/1000)%10)!=((i/10)%10))continue;
        c++;
    }
    printf("%d\n",c);
    return 0;
}
