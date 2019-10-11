#include <cstdio>
#include <cstring>
#include <algorithm>

int main(void){
    int i,l,cnt=0;
    char s[100001];
    scanf("%s",s);
    l = strlen(s);
    for(i=0;i<l;i++){
        if(s[i]=='0'+i%2)cnt++;
    }
    printf("%d\n",std::min(cnt,l-cnt));
    return 0;
}
