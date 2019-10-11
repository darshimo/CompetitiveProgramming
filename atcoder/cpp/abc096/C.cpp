#include <cstdio>

int main(){
    int i,j,h,w;
    scanf("%d %d",&h,&w);
    char s[h+2][w+2];
    for(i=1;i<=h;i++){
            scanf("%s",s[i]+1);
    }
    for(i=0;i<=h+1;i++){
        s[i][0]='.';
        s[i][w+1]='.';
    }
    for(i=0;i<=w+1;i++){
        s[0][i]='.';
        s[h+1][i]='.';
    }
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            if(s[i][j]=='#' && s[i-1][j]=='.' && s[i][j-1]=='.' && s[i+1][j]=='.' && s[i][j+1]=='.'){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
