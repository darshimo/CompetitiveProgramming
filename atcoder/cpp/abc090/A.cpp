#include <stdio.h>

int main(){
    char str[4];
    char ans[4];
    ans[3] = '\0';
    for(int i=0;i<3;i++){
        scanf("%s",str);
        ans[i] = str[i];
    }
    printf("%s",ans);
    return 0;
}
