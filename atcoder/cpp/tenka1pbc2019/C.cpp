#include <cstdio>
#include <cstring>

int main(void){
    int i,n,min=0;
    char stn[200000];
    int w[100000];
    int b[100000];
    scanf("%d",&n);
    scanf("%s",stn);
    char *tmp1 = stn;
    char *tmp2;
    int cnt=0;
    while(*tmp1!='\0'){
        tmp2 = tmp1;
        tmp1 += strspn(tmp1,".");
        w[cnt] = tmp1-tmp2;
        min += w[cnt];

        tmp2 = tmp1;
        tmp1 += strspn(tmp1,"#");
        b[cnt] = tmp1-tmp2;

        cnt++;
    }

    min -= w[0];
    int tmp = min;
    for(i=1;i<cnt;i++){
        tmp = tmp + b[i-1] - w[i];
        if(tmp<min)min = tmp;
    }
    printf("%d\n",min);
    return 0;
}
