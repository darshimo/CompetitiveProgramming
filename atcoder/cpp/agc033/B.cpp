#include <cstdio>

int h,w,n;
char S[200001];
char T[200001];

bool second(int, int, int, int *);

bool first(int i, int sr, int sc, int *param){
    if(sr<1||sr>h||sc<1||sc>w)return false;
    if(param[1]-param[4]>w-sc||param[0]-param[5]>sc-1||param[2]-param[7]>sr-1||param[3]-param[6]>h-sr)return false;

    if(S[i]=='L'){param[0]--;return second(i,sr,sc-1,param)&&second(i,sr,sc,param);}
    if(S[i]=='R'){param[1]--;return second(i,sr,sc+1,param)&&second(i,sr,sc,param);}
    if(S[i]=='U'){param[2]--;return second(i,sr-1,sc,param)&&second(i,sr,sc,param);}
                  param[3]--;return second(i,sr+1,sc,param)&&second(i,sr,sc,param);
}

bool second(int i, int sr, int sc, int *param){
    if(sr<1||sr>h||sc<1||sc>w)return false;//out
    if(i==n-1)return true;//end
    if(param[0]<=sc-1&&param[1]<=w-sc&&param[2]<=sr-1&&param[3]<=h-sr)return true;

    if(T[i]=='L'){param[4]--;return first(i+1,sr,sc-1,param)||first(i+1,sr,sc,param);}
    if(T[i]=='R'){param[5]--;return first(i+1,sr,sc+1,param)||first(i+1,sr,sc,param);}
    if(T[i]=='U'){param[6]--;return first(i+1,sr-1,sc,param)||first(i+1,sr,sc,param);}
                  param[7]--;return first(i+1,sr+1,sc,param)||first(i+1,sr,sc,param);
}

int main(void){
    int i,sr,sc;
    int param[8];
    for(i=0;i<8;i++)param[i]=0;
    scanf("%d %d %d",&h,&w,&n);
    scanf("%d %d",&sr,&sc);
    scanf("%s",S);
    scanf("%s",T);
    for(i=0;i<n;i++){
        if(S[i]=='L')param[0]++;
        else if(S[i]=='R')param[1]++;
        else if(S[i]=='U')param[2]++;
        else param[3]++;
        if(T[i]=='L')param[4]++;
        else if(T[i]=='R')param[5]++;
        else if(T[i]=='U')param[6]++;
        else param[7]++;
    }

    if(first(0,sr,sc,param))printf("YES\n");
    else printf("NO\n");

    return 0;
}
