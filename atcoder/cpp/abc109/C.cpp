#include <cstdio>
#include <cstdlib>

int gcd(int a, int b){
    int mod = a % b;
    if(mod == 0)
        return b;
    return gcd(b, mod);
}

int main(){
    int i, n, xs, d;
    scanf("%d %d",&n,&xs);
    int *x = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",x+i);
        x[i] = abs(x[i]-xs);
    }
    for(i=0;i<n;i++){
        if(x[i]>0){
            d = x[i];
            break;
        }
    }
    for(;i<n;i++){
        if(x[i]>0){
            d = gcd(d,x[i]);
        }
    }
    printf("%d\n",d);
    return 0;
}
