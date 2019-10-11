#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
    int i,j,h,w;
    char a[1000][1001];

    int d1=2000,d2=2000,d3=2000,d4=2000;

    scanf("%d %d",&h,&w);
    for(i=0;i<h;i++){
        scanf("%s",a[i]);
        for(j=0;j<w;j++){
            if(a[i][j]=='#'){
                if(i+j<d1)d1=i+j;
                if(i+w-1-j<d2)d2=i+w-1-j;
                if(h-1-i+j<d3)d3=h-1-i+j;
                if(h-i-j+w-1-i)d4=h-i-j+w-1-i;
            }
        }
    }

    printf("%d\n",max(max(d1,d2),max(d3,d4)));

    return 0;
}
