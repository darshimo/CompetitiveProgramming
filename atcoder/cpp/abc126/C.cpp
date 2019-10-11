#include <cstdio>
#include <cmath>

int main(void){
    int n,k;
    double sum=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        double tmp=0;
        double lki= log2(k) - log2(i);
        while(true){
            if(tmp>=lki)break;
            tmp++;
        }
        sum += (1.0/(double)n)*pow((1.0/2.0),tmp);
    }
    printf("%.16f\n",sum);
    return 0;
}
