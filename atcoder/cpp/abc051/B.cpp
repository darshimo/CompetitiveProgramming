#include <cstdio>
#include <algorithm>
using namespace std;

int comb(int n,int r){
    r = min(r,n-r);
    int ans;
    if(r==0){
        ans = 1;
    }else{
        ans = comb(n,r-1) * (n-r+1) / r;
    }
    return ans;
}

int main(void){
    int x,y,z,k,s;
    scanf("%d %d",&k,&s);
    int cnt=0;
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            if(0<=s-x-y&&s-x-y<=k)cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
