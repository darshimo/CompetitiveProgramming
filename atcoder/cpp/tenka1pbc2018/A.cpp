#include <stdio.h>
#include <string.h>

int main(){
    char s[4];
    scanf("%s",s);
    if(strlen(s)==2){
        printf("%s\n",s);
    }else{
        printf("%c%c%c\n",s[2],s[1],s[0]);
    }
    return 0;
}
