#include <stdio.h>

int main(void){
    int i,n;
    int h[20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",h+i);
    }
    int count = 1;
    int max = h[0];
    for(i=1;i<n;i++){
        if(h[i]<max)continue;
        else{
            max = h[i];
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
