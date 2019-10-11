#include <stdio.h>

int main(){
    int n, i, j, v;
    scanf("%d",&n);
    int *a = new int [n];
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=0;i<n;i++){
        v = a[i];
        j = i-1;
        while(j>=0&&v<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(j=0;j<n;j++){
            if(j>0)printf(" ");
            printf("%d",a[j]);
        }
        printf("\n");
    }
    return 0;
}
