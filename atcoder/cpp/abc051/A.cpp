#include <cstdio>

int main(void){
    char s[20];
    scanf("%s",s);
    for(int i=0;i<19;i++){
        if(s[i]==',')s[i]=' ';
    }
    printf("%s\n",s);
    return 0;
}
