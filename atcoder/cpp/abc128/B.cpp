#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;

struct data{
    int num;
    char s[11];
    int p;
    bool operator<(const data &ob)const{
        if(strcmp(this->s,ob.s)==0){
            return (this->p>ob.p);
        }
        return (strcmp(this->s,ob.s)<0);
    }
};

int main(void){
    int n;
    vector<data> d;//(100);
    data tmp;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d",tmp.s,&(tmp.p));
        tmp.num = i+1;
        d.push_back(tmp);
    }

    sort(d.begin(),d.end());

    for(int i=0;i<n;i++){
        tmp = d[i];
        printf("%d\n",tmp.num);
    }

    return 0;
}
