#include <cstdio>

int search(int *s, int n, int t){
    int ret = 0;
    if(t==s[n/2])ret = 1;
    else if(n<=1)ret = 0;
    else if(t<s[n/2])ret = search(s, n/2, t);
    else ret = search(s+n/2, (n+1)/2, t);
    return ret;
}

int main(){
    int i, n, q, t;
    int c = 0;
    scanf("%d",&n);
    int s[n];
    for(i=0;i<n;i++){
        scanf("%d",s+i);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&t);
        c += search(s, n, t);
    }
    printf("%d\n",c);
    return 0;
}
