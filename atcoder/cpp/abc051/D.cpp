#include <cstdio>
#include <climits>
#include <queue>
using namespace std;

int N[100][100];
int dist[100][100];
bool check[100][100];

void dikstra(int v, int n){
    priority_queue< pair<int, int> > q;

    dist[v][v] = 0;
    for(i=0;i<n;i++){
        if(i!=v)q.push(make_pair(N[v][i],i);
    }

    while(q.size()>0){
        pair<int, int> p = q.pop();
        d = p.first;
        u = p.second;
    }

    return;
}

int main(void){
    int i,j,n,m,a,b,c;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            check[i][j] = false;
            N[i][j] = INT_MAX;
        }
    }

    for(i=0;i<m;i++){
        scanf("%d %d %c",&a,&b,&c);
        N[a][b]=c;
        N[b][a]=c;
    }

    for(i=0;i<n;i++){
        dikstra(i,n);
    }

    return 0;
}
