#include <cstdio>

#define SWAP(a,b) (a += b,b = a - b,a -= b)

int gcd(int a, int b){
    if(b<a)SWAP(a,b);
    int tmp;
    while(a!=0){
        tmp = b%a;
        b = a;
        a = tmp;
    }
    return b;
}

int main(void){
    int i,n;
    int a[100000];
    int gcd_array[100000];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }

    gcd_array[0] = 0;
    int tmp = 0;
    for(i=1;i<n;i++){
        tmp = gcd(tmp,a[i-1]);
        gcd_array[i] = tmp;
    }

    tmp = 0;
    for(i=n-2;i>=0;i--){
        tmp = gcd(tmp,a[i+1]);
        gcd_array[i] = gcd(tmp,gcd_array[i]);
    }

    int max = gcd_array[0];
    for(i=1;i<n;i++){
        if(gcd_array[i]>max)max = gcd_array[i];
    }

    printf("%d\n",max);
    return 0;
}
