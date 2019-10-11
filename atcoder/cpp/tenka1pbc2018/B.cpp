#include <stdio.h>

int main(){
    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);
    while(true){
        if(K<=0)break;
        A/=2;
        B+=A;
        K--;

        if(K<=0)break;
        B/=2;
        A+=B;
        K--;
    }
    printf("%d %d\n",A,B);
    return 0;
}
