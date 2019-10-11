#include <cstdio>
#include <cstdlib>

char *zero(){
    char *p = (char *)malloc(sizeof(char)*20);
    for(int i=0;i<20;i++)p[i]=0;
    return p;
}

void add(char *a1, char *a2){
    for(int i=0;i<20;i++)a1[i]+=a2[i];
    return;
}

void sub(char *a1, char *a2){
    for(int i=0;i<20;i++)a1[i]-=a2[i];
    return;
}

bool ok(char *a1, char *a2){
    for(int i=0;i<20;i++){
        if(a1[i]*a2[i])return false;
    }
    return true;
}

char *setbit(int A){
    char *p = (char *)malloc(sizeof(char)*20);
    for(int i=0;i<20;i++){
        p[i]=A%2;
        A/=2;
    }
    return p;
}

int main(){

    int i,n;
    scanf("%d",&n);
    int *A = (int *)malloc(sizeof(int)*n);
    char **a = (char **)malloc(sizeof(char *)*n);
    for(i=0;i<n;i++){
        scanf("%d",A+i);
        a[i] = setbit(A[i]);
    }

    int j = 0;
    int c = 0;
    char *tmp=zero();
    for(i=0;i<n;i++){
        while(j<n&&ok(tmp,a[j])){
            add(tmp,a[j]);
            j++;
        }
        sub(tmp,a[i]);
        c+=j-i;
    }

    printf("%d\n",c);
    return 0;
}
