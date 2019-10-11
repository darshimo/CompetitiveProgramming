#include <stdio.h>
#include <math.h>

int insertionSort(int *a, int n, int g){
    int i, j, v;
    int cnt = 0;
    for(i=g;i<n;i++){
        v = a[i];
        j = i - g;
        while(j>=0&&a[j]>v){
            a[j+g] = a[j];
            j -= g;
            cnt++;
        }
        a[j+g] = v;
    }
    return cnt;
}

int shellSort(int *a, int n){
    int cnt = 0;
    int i;
    int m = int(log(n)/log(2)) + 1;
    printf("%d\n",m);
    int *g = new int [m];
    for(i=0;i<m;i++){
        g[i] = pow(2,m-1-i);
    }
    for(i=0;i<m;i++){
        if(i>0)printf(" ");
        printf("%d",g[i]);
    }
    printf("\n");
    for(i=0;i<m;i++)cnt+=insertionSort(a,n,g[i]);
    return cnt;
}

int main(){
    int i, n, cnt;
    scanf("%d",&n);
    int *a = new int [n];
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    cnt = shellSort(a,n);
    printf("%d\n",cnt);
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
