#include <cstdio>
#include <cstring>

void furui(char *a){
    int i,j;
    a[0]=0;
    a[1]=0;
    for(i=2;i<55556;i++){
        if(a[i])for(j=2;j*i<55556;j++)a[i*j]=0;
    }
    for(i=1;i<55556;i++)if(i%5!=1)a[i]=0;
}

int main(){
    int i,j,n,tmp;
    char a[55556];
    memset(a,1,sizeof(char)*55556);
    furui(a);
    scanf("%d",&n);
    j=0;
    for(i=2;j<n;i++){
        if(a[i]){
            printf("%d\n",i);
            j++;
        }
    }
    return 0;
}
