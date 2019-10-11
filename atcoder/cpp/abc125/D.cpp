#include <cstdio>

int main(void){
    int i,n,tmp,min=1000000001;
    int cnt=0;
    long int sum = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp<0){
            cnt++;
            tmp = -tmp;
        }
        sum += tmp;
        if(min>tmp)min=tmp;
    }
    if(cnt%2){
        sum -= 2*min;
    }
    printf("%ld\n",sum);
    return 0;
}
