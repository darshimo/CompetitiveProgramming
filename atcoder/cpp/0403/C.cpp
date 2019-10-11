#include <stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    char name[11];
    unsigned long long c[5] = {0,0,0,0,0};
    int i,j,k;
    for(i=0;i<n;i++){
        scanf("%s",name);
        switch(name[0]){
        case 'M':
            c[0]++;
            break;
        case 'A':
            c[1]++;
            break;
        case 'R':
            c[2]++;
            break;
        case 'C':
            c[3]++;
            break;
        case 'H':
            c[4]++;
            break;
        default:
            break;
        }
    }
    unsigned long long ans = 0;
    for(i=0;i<3;i++){
        for(j=i+1;j<4;j++){
            for(k=j+1;k<5;k++){
                ans += c[i]*c[j]*c[k];
            }
        }
    }
    printf("%llu\n",ans);
    return 0;
}
