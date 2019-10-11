#include <cstdio>
#include <vector>
#include <algorithm>

typedef struct{
    long long int price;
    long long int number;
}shop;

bool operator<(const shop& left, const shop& right){
    return left.price < right.price;
}

int main(){
    int i,n,m;
    std::vector<shop> data;
    shop a;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&(a.price),&(a.number));
        data.push_back(a);
    }
    std::sort(data.begin(),data.end());
    long long int ret=0;
    for(i=0;i<n;i++){
        a = data[i];
        if(a.number>=m){
            ret += a.price * m;
            break;
        }else{
            ret += a.price * a.number;
            m -= a.number;
        }
    }
    printf("%lld\n",ret);
    return 0;
}
