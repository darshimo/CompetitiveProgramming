#include <cstdio>

int main(void){
    int n,k;
    char s[100];
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    int a = 'a' - 'A';
    s[k-1] = s[k-1]+a;
    printf("%s\n",s);
    return 0;
}
