#include <cstdio>
#include <cstdlib>

int main(void){
    char s[5];
    char a[3],b[3];
    scanf("%s",s);
    a[0] = s[0];
    a[1] = s[1];
    a[2] = '\0';
    b[0] = s[2];
    b[1] = s[3];
    b[2] = '\0';
    int c = atoi(a);
    int d = atoi(b);
    bool ym,my;
    if(c==0||c>12){
        if(d==0||d>12){
            printf("NA\n");
        }else{
            printf("YYMM\n");
        }
    }else{
        if(d==0||d>12){
            printf("MMYY\n");
        }else{
            printf("AMBIGUOUS\n");
        }
    }
    return 0;
}
