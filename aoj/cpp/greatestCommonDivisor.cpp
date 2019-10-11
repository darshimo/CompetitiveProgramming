#include <cstdio>

int gcd(int x, int y){
    if(x==0)return y;
    else return gcd(y%x,x);
}

int main(){
    int x,y,z;
    scanf("%d %d",&x,&y);
    if(x<y)z=gcd(x,y);
    else z=gcd(y,x);
    printf("%d\n",gcd(x,y));
    return 0;
}
