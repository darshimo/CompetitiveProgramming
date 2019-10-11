#include <cstdio>
#include <cmath>

int main(){
    int a,b,c,k,ans;
    scanf("%d %d %d %d",&a,&b,&c,&k);
    if(a<b){
        if(b<c)ans = a+b+c*pow(2,k);
        else ans = a+c+b*pow(2,k);
    }else{
        if(a<c)ans = a+b+c*pow(2,k);
        else ans = b+c+a*pow(2,k);
    }
    printf("%d\n",ans);
    return 0;
}
