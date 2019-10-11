#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    char c;
    char *p = "Three\0";
    for(i=0;i<n;i++){
        scanf("%c",&c);
        if(c=='Y')p="Four\0";
    }
    printf("%s\n",p);
    return 0;
}
