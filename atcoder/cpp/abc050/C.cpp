#include <cstdio>
#include <cmath>
using namespace std;

int main(void){
    int i,num,n,m,a[100000],max=0;
    scanf("%d",&n);
    m=n/2;
    if(n%2==1){
        num = 2*m*(m+1);
    }else{
        num = 2*m*m;
    }
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }

    if(check(n,a))printf("%d\n",(int)pow(2,m));
    else printf("0\n");

    return 0;
}
