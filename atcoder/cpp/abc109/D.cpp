#include <cstdio>
#include <cstdlib>

void movex(int **a, int i,int w){
    for(int j=1;j<w;j++){
        if(a[i][j]){
            a[i][j+1]=(a[i][j+1]+1)%2;
            printf("%d %d %d %d\n",i,j,i,j+1);
        }
    }
    return;
}

void movey(int **a, int h, int j){
    for(int i=1;i<h;i++){
        if(a[i][j]){
            a[i+1][j]=(a[i+1][j]+1)%2;
            printf("%d %d %d %d\n",i,j,i+1,j);
        }
    }
    return;
}

int count(int **a, int h, int w){
    int i,j,c,tmp,total;
    c = 0;
    int *b = (int *)malloc(sizeof(int)*h+1);
    for(i=1;i<h+1;i++){
        tmp = 0;
        for(j=1;j<w;j++){
            tmp = (a[i][j]+tmp)%2;
            if(tmp){
                c++;
            }
        }
        b[i] = (a[i][w]+tmp)%2;
    }
    tmp = 0;
    for(i=1;i<h;i++){
        tmp = (b[i]+tmp)%2;
        if(tmp){
            c++;
        }
    }
    return c;
}

int main(){
    int i,j,h,w,tmp;
    scanf("%d %d",&h,&w);
    int **a = (int **)malloc(sizeof(int*)*(h+1));
    for(i=0;i<h+1;i++)a[i]=(int*)malloc(sizeof(int)*(w+1));
    for(i=1;i<h+1;i++){
        for(j=1;j<w+1;j++){
            scanf("%d",&tmp);
            a[i][j] = tmp%2;
        }
    }
    printf("%d\n",count(a,h,w));
    for(i=1;i<h+1;i++){
        movex(a,i,w);
    }
    movey(a,h,w);
    return 0;
}
