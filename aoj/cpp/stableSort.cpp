#include <stdio.h>
#include <string.h>

int bubbleSort(char (*a)[3], int n){
    int i = 0;
    char tmp;
    int c;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j=n-1;j>i;j--){
            if(a[j][1]<a[j-1][1]){
                tmp = a[j][0];
                a[j][0] = a[j-1][0];
                a[j-1][0] = tmp;
                tmp = a[j][1];
                a[j][1] = a[j-1][1];
                a[j-1][1] = tmp;
                flag = 1;
                c++;
            }
        }
        i++;
    }
    return c;
}

int selectionSort(char (*a)[3], int n){
    int i, j, minj;
    char tmp;
    int c = 0;
    for(i=0;i<n;i++){
        minj = i;
        for(j=i+1;j<n;j++){
            if(a[j][1]<a[minj][1])minj = j;
        }
        if(minj!=i){
            tmp = a[i][0];
            a[i][0] = a[minj][0];
            a[minj][0] = tmp;
            tmp = a[i][1];
            a[i][1] = a[minj][1];
            a[minj][1] = tmp;
            c++;
        }
    }
    return c;
}

int stability(char (*in)[3], char (*out)[3], int n){
    int i,j,a,b;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(a=0;a<n;a++){
                for(b=a+1;b<n;b++){
                    if(in[i][1]==in[j][1]&&in[i][0]==out[b][0]&&in[i][1]==out[b][1]&&in[j][0]==out[a][0]&&in[j][1]==out[a][1])return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int i, n, count_select, count_bubble;
    scanf("%d",&n);
    char (*a)[3] = new char [n][3];
    char (*b)[3] = new char [n][3];
    char (*s)[3] = new char [n][3];
    for(i=0;i<n;i++)scanf("%s",a[i]);

    for(i=0;i<n;i++){
        strcpy(b[i],a[i]);
        strcpy(s[i],a[i]);
    }

    count_bubble = bubbleSort(b,n);
    count_select = selectionSort(s,n);

    for(i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%s",b[i]);
    }
    if(stability(a,b,n)){
        printf("\nNot stable\n");
    }else{
        printf("\nStable\n");
    }

    for(i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%s",s[i]);
    }
    if(stability(a,s,n)){
        printf("\nNot stable\n");
    }else{
        printf("\nStable\n");
    }
    return 0;
}
