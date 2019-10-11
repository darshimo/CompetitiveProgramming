#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(){
    int i, j, n;
    scanf("%d",&n);
    char** w = (char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        w[i] = (char*)malloc(sizeof(char)*11);
        scanf("%s",w[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(w[i],w[j])==0){
                printf("No\n");
                return 0;
            };
        }
    }
    for(i=0;i<n-1;i++){
        char a = w[i][strlen(w[i])-1];
        char b = w[i+1][0];
        if(a!=b){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
