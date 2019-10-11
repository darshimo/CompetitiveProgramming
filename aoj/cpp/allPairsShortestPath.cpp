#include <cstdio>
#include <cstdlib>

void func(int **D, bool **pass, int V){
    int i,j,k;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            for(k=0;k<V;k++){
                if(pass[j][i] && pass[i][k]){
                    if(!pass[j][k]){
                        D[j][k] = D[j][i] + D[i][k];
                        pass[j][k] = true;
                    }else{
                        if(D[j][i] + D[i][k] < D[j][k]){
                            D[j][k] = D[j][i] + D[i][k];
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int i,j,s,t,d,V,E;
    scanf("%d %d",&V,&E);

    int **D = (int **)malloc(sizeof(int *)*V);
    bool **pass = (bool **)malloc(sizeof(bool *)*V);
    for(i=0;i<V;i++){
        D[i] = (int *)malloc(sizeof(int)*V);
        pass[i] = (bool *)malloc(sizeof(bool)*V);
        for(j=0;j<V;j++){
            D[i][j] = 0;
            if(i==j) pass[i][j] = true;
            else pass[i][j] = false;
        }
    }

    for(i=0;i<E;i++){
        scanf("%d %d %d",&s,&t,&d);
        D[s][t] = d;
        pass[s][t] = true;
    }

    func(D,pass,V);

    for(i=0;i<V;i++){
        if(D[i][i]<0){
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(pass[i][j])printf("%d",D[i][j]);
            else printf("INF");
            if(j<V-1)printf(" ");
            else printf("\n");
        }
    }

    return 0;
}
