#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <map>
using namespace std;

typedef map<int, int>::iterator mitr;

map<int, int> w[10000];
int d[10000];
char pos[10000];

priority_queue<pair<int,int> > others;
pair<int,int> p;

void findPath(){
    p = others.top();
    others.pop();
    while(pos[p.second]){
        p = others.top();
        others.pop();
    }
    pos[p.second]=1;

    int tmpu = p.second;
    int tmpd = -p.first;

    for(mitr i=w[tmpu].begin();i!=w[tmpu].end();i++){
        if(tmpd + i->second < d[i->first]){
            d[i->first] = tmpd + i->second;
            others.push(make_pair(-d[i->first],i->first));
        }
    }
}

int main(){
    int i,j,u,k,n,v,c;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        for(j=0;j<k;j++){
            scanf("%d %d",&v,&c);
            w[u][v] = c;
        }
    }

    memset(pos,0,sizeof(char)*100);
    for(i=0;i<n;i++)d[i]=INT_MAX;
    d[0] = 0;
    others.push(make_pair(0,0));
    for(i=0;i<n;i++)findPath();
    for(i=0;i<n;i++)printf("%d %d\n",i,d[i]);

    return 0;
}
