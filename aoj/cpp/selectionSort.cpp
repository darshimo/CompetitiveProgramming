#include <stdio.h>

int selectionSort(int *a, int n){
    int i, j, tmp, minj;
    int c = 0;
    for(i=0;i<n;i++){
        minj = i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[minj])minj = j;
        }
        if(minj!=i){
            tmp = a[i];
            a[i] = a[minj];
            a[minj] = tmp;
            c++;
        }
    }
    return c;
}

int main(){
    int i, n, count;
    scanf("%d",&n);
    int *a = new int [n];
    for(i=0;i<n;i++)scanf("%d",a+i);
    count = selectionSort(a,n);
    for(i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",count);
    return 0;
}
