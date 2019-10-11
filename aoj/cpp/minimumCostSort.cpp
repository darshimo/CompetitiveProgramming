#include <cstdio>
#include <algorithm>
using namespace std;

int researchRoop(int *s, int *pos, int p, int min){
    int tmp;
    int rmin = 10000;
    int size = 0;
    int sum = 0;

    while(s[p]>=0){
        tmp = s[p];
        if(tmp<rmin)rmin = tmp;
        sum += tmp;
        size++;
        s[p] = -1;
        p = pos[tmp];
    }

    int ans1 = rmin + sum + (size+1)*min;
    int ans2 = (size-2)*rmin + sum;
    return std::min(ans1,ans2);
}

void quickSort(int *s, int n){
    if(n<=1)return;
    int i=0;
    int tmp;
    int key = s[n-1];
    for(int j=0;j<n;j++){
        if(s[j]>key)continue;
        if(i<j){
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
        i++;
    }

    quickSort(s,i-1);
    quickSort(s+i-1,n-i+1);
}

int main(){
    int w[1000];
    int s[1000];
    int pos[10001];
    int i,n,c=0;
    int min = 10000;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",w+i);
        s[i] = w[i];
        pos[w[i]] = i;
        if(w[i]<min)min=w[i];
    }
    quickSort(s,n);
    for(i=0;i<n;i++)if(s[i]==w[i])s[i]=-1;

    for(i=0;i<n;i++){
        if(s[i]<0)continue;
        c += researchRoop(s,pos,i,min);
    }

    printf("%d\n",c);

    return 0;
}
