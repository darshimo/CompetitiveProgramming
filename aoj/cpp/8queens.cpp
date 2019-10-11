#include <cstdio>

int main(){
    int i,j,k,r,c;
    char board[8][8];
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            board[i][j] = '.';
        }
    }

    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d %d",&r,&c);
        board[r][c] = 'Q';
    }

    putQueens(board);

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
