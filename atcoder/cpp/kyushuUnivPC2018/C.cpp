#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int h,w,x;
char s[1000][1000];
typedef struct{
    int h;
    int w;
    int d;
}step;
queue<step> root;

void ino2wall(int i, int j){
    int k,l,tmp;
    for(k=-x;k<=x;k++){
        if(i+k<0||i+k>=h)continue;
        tmp = x-abs(k);
        for(l=j-tmp;l<=j+tmp;l++){
            if(l<0||l>=w)continue;
            //printf("%d,%d\n",k,l);
            if(s[i+k][l]=='.'||s[i+k][l]=='G'||s[i+k][l]=='@')s[i+k][l]='#';
        }
    }
    return;
}

int calc(){
    step tmp,tmp1;
    while(true){
        tmp = root.front();
        //printf("%d %d %d\n",tmp.h,tmp.w,tmp.d);
        root.pop();
        if(s[tmp.h][tmp.w]=='G')return tmp.d;

        s[tmp.h][tmp.w]='#';
        if(s[tmp.h-1][tmp.w]=='.' || s[tmp.h-1][tmp.w]=='G'){
            tmp1.h = tmp.h-1;
            tmp1.w = tmp.w;
            tmp1.d = tmp.d + 1;
            root.push(tmp1);
        }
        if(s[tmp.h+1][tmp.w]=='.' || s[tmp.h+1][tmp.w]=='G'){
            tmp1.h = tmp.h+1;
            tmp1.w = tmp.w;
            tmp1.d = tmp.d + 1;
            root.push(tmp1);
        }
        if(s[tmp.h][tmp.w-1]=='.' || s[tmp.h][tmp.w-1]=='G'){
            tmp1.h = tmp.h;
            tmp1.w = tmp.w-1;
            tmp1.d = tmp.d + 1;
            root.push(tmp1);
        }
        if(s[tmp.h][tmp.w+1]=='.' || s[tmp.h][tmp.w+1]=='G'){
            tmp1.h = tmp.h;
            tmp1.w = tmp.w+1;
            tmp1.d = tmp.d + 1;
            root.push(tmp1);
        }

        if(root.empty())break;
    }
    return -1;
}

int main(){
    int i,j;
    scanf("%d %d %d",&h,&w,&x);
    for(i=0;i<h;i++){
        scanf("%s",s[i]);
    }

    step tmp;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j]=='S'){
                tmp.h = i;
                tmp.w = j;
                tmp.d = 0;
                root.push(tmp);
            }
            if(s[i][j]=='@')ino2wall(i,j);
        }
    }

    for(i=0;i<h;i++){
        //printf("%s\n",s[i]);
    }

    printf("%d\n",calc());


    return 0;
}
