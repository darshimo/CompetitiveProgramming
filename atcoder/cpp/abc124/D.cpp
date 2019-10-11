#include <cstdio>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>

int main(void){
    int tmp,n,k;
    char s[100001];
    std::vector<int> v0;
    std::vector<int> v1;
    scanf("%d %d\n",&n,&k);
    scanf("%s",s);
    char *tmp1,*tmp2;

    int m=0;
    tmp1=s;

    v1.push_back(0);
    while(*tmp1!='\0'){
        tmp2=tmp1;
        tmp1+=strspn(tmp1,"0");
        tmp = tmp1-tmp2;
        v0.push_back(tmp);

        tmp2=tmp1;
        tmp1+=strspn(tmp1,"1");
        tmp = tmp1-tmp2;
        v1.push_back(tmp);

        m++;
    }

    tmp = v1[0];
    int i = 0;
    for(;i<std::min(k,m);i++){
        tmp += v0[i] + v1[i+1];
    }
    int ans = tmp;
    for(;i<m;i++){
        tmp = tmp -v0[i-k]-v1[i-k]+v0[i]+v1[i+1];
        if(tmp>ans)ans=tmp;
    }
    printf("%d\n",ans);

    return 0;
}
