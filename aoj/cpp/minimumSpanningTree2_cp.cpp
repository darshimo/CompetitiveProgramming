#include <cstdio>
#include <vector>
using namespace std;

vector<int> a[10000];
int d[10000][10000];
bool check[10000];
int cost[10000];

class priorityQueue{
    int queue[10001];
    int n;
public:
    priorityQueue(int m);
    void alignment();
    int maxHeapify(int c);
    int pop();
    int size();
};

priorityQueue::priorityQueue(int m){
    n=m;
    for(int i=1;i<=n;i++){
        queue[i] = i-1;
    }
    return;
}

int priorityQueue::size(){
    return n;
}

int priorityQueue::pop(){
    int ret = queue[1];
    queue[1] = queue[n];
    n--;
    return ret;
}

int priorityQueue::maxHeapify(int c){
    int l = 2*c;
    int r = 2*c+1;
    //printf("%d %d %d\n",c,l,r);

    int smallest = c;
    if(l<=n){
        if(cost[queue[l]] < cost[queue[smallest]])smallest = l;
    }
    if(r<=n){
        if(cost[queue[r]] < cost[queue[smallest]])smallest = r;
    }

    if(smallest == c)return smallest;

    int tmp = queue[c];
    queue[c] = queue[smallest];
    queue[smallest] = tmp;

    return smallest;
}

void priorityQueue::alignment(){
    int i,tmp1,tmp2;
    for(i = n/2;i>0;i--){
        tmp2 = i;
        while(true){
            tmp1 = maxHeapify(tmp2);
            if(tmp1==tmp2)break;
            else tmp2 = tmp1;
        }
    }
    return;
}

int makeTree(priorityQueue &pq){
    int i,u,v,ret;

    ret = 0;

    while(pq.size()){
        u = pq.pop();
        //printf("u:%d\n",u);
        check[u] = true;
        for(i=0;i<a[u].size();i++){
            v = a[u][i];
            if(check[v])continue;
            if(d[u][v] < cost[v])cost[v] = d[u][v];
        }
        pq.alignment();
        ret += cost[u];
    }

    return ret;
}

int main(){
    int i,s,t,w,V,E;

    scanf("%d %d",&V,&E);

    cost[0] = 0;
    for(i=1;i<V;i++){
        cost[i] = 1000000;
    }
    for(i=0;i<V;i++){
        check[i] = false;
    }

    priorityQueue pq(V);

    for(i=0;i<E;i++){
        scanf("%d %d %d",&s,&t,&w);
        a[s].push_back(t);
        a[t].push_back(s);
        d[s][t] = w;
        d[t][s] = w;
    }

    printf("%d\n",makeTree(pq));

    return 0;
}
