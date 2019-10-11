#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

int x,y,z,k;
std::vector<long int> a(1000);
std::vector<long int> b(1000);
std::vector<long int> c(1000);

bool solve(int p){
    int cnt = 0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                if(a[i]+b[j]+c[k]<p)break;
                cnt++;
                if(cnt>=k)return true;
            }
        }
    }
    return false;
}

int main(void){
    int i;
    long int tmp;
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    scanf("%d",&k);
    for(i=0;i<x;i++){
        scanf("%ld",&tmp);
        a.push_back(tmp);
    }
    for(i=0;i<y;i++){
        scanf("%ld",&tmp);
        b.push_back(tmp);
    }
    for(i=0;i<z;i++){
        scanf("%ld",&tmp);
        c.push_back(tmp);
    }

    std::sort(a.begin(),a.end(),std::greater<long int>());
    std::sort(b.begin(),b.end(),std::greater<long int>());
    std::sort(c.begin(),c.end(),std::greater<long int>());

    long int min=0;
    long int max=x*y*z+1;
    long int mid;
    while(true){
        mid=(min+max)/2;
        if(solve(mid))min = mid;
        else max = mid;
        if((max-min)==1)break;
    }

    long int border = min;

    int cnt;
    std::vector<long int> sum(k,0);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                if(a[i]+b[j]+c[k]<border+1)break;
                cnt++;
                sum.push_back(a[i]+b[j]+c[k]);
            }
        }
    }

    std::sort(sum.begin(),sum.end(),std::greater<long int>());

    for(int i=0;i<std::min(cnt,k);i++)printf("%ld\n",sum[i]);
    for(int i=0;i<std::max(k-cnt,0);i++)printf("%ld\n",border);

    return 0;
}
