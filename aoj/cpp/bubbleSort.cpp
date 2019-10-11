#include <stdio.h>

int bubbleSort(int *a, int n){
    int i = 0;
    int tmp, c;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                c++;
            }
        }
        i++;
    }
    return c;
}

int main(){
    int i, n, count;
    scanf("%d",&n);
    int *a = new int [n];
    for(i=0;i<n;i++)scanf("%d",a+i);

    count = bubbleSort(a, n);

    for(i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",count);

    return 0;
}
