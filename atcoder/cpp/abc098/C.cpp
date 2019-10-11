#include <cstdio>
#include <cstdlib>

int leader(char *s, int n, int E, int W){
    int c=n;
    int e=0;
    int w=0;
    int tmp;

    for(int i=0;i<n;i++){
        if(s[i]=='E'){
            tmp = w+E-e-1;
            e++;
        }else{
            tmp = w+E-e;
            w++;
        }
        if(tmp<c)c=tmp;

    }

    return c;
}

int main(){
    int i,n;
    char *s;
    scanf("%d",&n);
    s = (char *)malloc(sizeof(char)*(n+1));
    scanf("%s",s);
    int E=0;
    int W=0;
    for(i=0;i<n;i++){
        if(s[i]=='E')E++;
        else W++;
    }
    printf("%d\n",leader(s,n,E,W));
    return 0;
}
