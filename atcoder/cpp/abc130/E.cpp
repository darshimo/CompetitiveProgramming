#include <cstdio>

int n,m;
int s[2000];
int t[2000];
long int matrix_f[2000][2000];
long int matrix_g[2000][2000];

long int g(int, int );

long int f(int a, int b){
    if(matrix_f[a][b]>=0)return matrix_f[a][b];
    if(a>=n||b>=m)return 0;
    long int ans = (f(a+1,b) + g(a,b))%1000000007;
    matrix_f[a][b] = ans;
    return ans;
}

long int g(int a, int b){
    if(matrix_g[a][b]>=0)return matrix_g[a][b];
    long int ans = 0;
    for(int i=b;i<m;i++){
        if(t[i]!=s[a])continue;
        ans += (1+f(a+1,i+1))%1000000007;
        ans %= 1000000007;
    }
    matrix_g[a][b] = ans;
    return ans;
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matrix_f[i][j]=-1;
            matrix_g[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d",s+i);
    }
    for(int i=0;i<m;i++){
        scanf("%d",t+i);
    }
    printf("%ld\n",f(0,0)+1);
    return 0;
}
