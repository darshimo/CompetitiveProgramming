#include <cstdio>

int main(void){
    int sx,sy,tx,ty;
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    int dx = tx-sx;
    int dy = ty-sy;
    int i;
    for(i=0;i<dy;i++)printf("U");
    for(i=0;i<dx;i++)printf("R");
    for(i=0;i<dy;i++)printf("D");
    for(i=0;i<dx;i++)printf("L");

    printf("L");
    for(i=0;i<dy+1;i++)printf("U");
    for(i=0;i<dx+1;i++)printf("R");
    printf("D");
    printf("R");
    for(i=0;i<dy+1;i++)printf("D");
    for(i=0;i<dx+1;i++)printf("L");
    printf("U");

    printf("\n");

    return 0;
}
