#include <stdio.h>

int main(void){
    int tmp,q,minq=10,sum=0,count=0;
    for(int i=0;i<5;i++){
        scanf("%d",&tmp);
        q = tmp%10;
        sum += tmp - q;
        if(q){
            count++;
            if(q<minq)minq=q;
        }
    }
    if(minq==10)printf("%d\n",sum);
    else printf("%d\n",sum+10*(count-1)+minq);
    return 0;
}
