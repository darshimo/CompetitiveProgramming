#include <cstdio>

int search(int m, int *A, int n){
    int tmp1, tmp2, ret;
    if(n==0)ret = 0;
    else if(m<A[0])ret = search(m, A+1, n-1);
    else if(m==A[0])ret = 1;
    else if(m>A[0]){
        tmp1 = search(m-A[0], A+1, n-1);
        tmp2 = search(m, A+1, n-1);
        ret = tmp1 + tmp2;
    }
    return ret;
}

int main(){
    int i, n, q, m;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++)scanf("%d",A+i);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&m);
        if(search(m, A, n))printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
