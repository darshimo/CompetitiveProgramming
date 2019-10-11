#include <cstdio>
#include <cstring>
#include <algorithm>

int count(int (*common)[1001], char *x, char *y, int n1, int n2){
    if(n1*n2==0)return 0;
    else if(common[n1][n2]<0){
        if(x[n1]==y[n2])common[n1][n2] = 1 + count(common,x,y,n1-1,n2-1);
        else common[n1][n2] = std::max(count(common,x,y,n1-1,n2),count(common,x,y,n1,n2-1));
    }
    return common[n1][n2];
}

int main(){
    int i, j, k, q;
    char c;
    char x[1002], y[1002];
    int common[1001][1001];
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%s",x+1);
        scanf("%s",y+1);
        int n1 = strlen(x+1);
        int n2 = strlen(y+1);
        for(j=1;j<=n1;j++){
            for(k=1;k<=n2;k++){
                common[j][k] = -1;
            }
        }
        printf("%d\n",count(common,x,y,n1,n2));
    }
    return 0;
}
