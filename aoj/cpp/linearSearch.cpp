#include <cstdio>

int main(){
    int i, j, n, q, t;
    int c = 0;
    scanf("%d",&n);
    int s[n];
    for(i=0;i<n;i++){
        scanf("%d",s+i);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&t);
        for(j=0;j<n;j++){
            if(t==s[j]){
                c++;
                break;
            }
        }
    }
    printf("%d\n",c);
    return 0;
}
