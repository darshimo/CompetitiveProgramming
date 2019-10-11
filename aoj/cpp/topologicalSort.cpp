#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

stack<int> st;

void topologicalSort(vector<int> *a, int u, bool *check){
    if(check[u])return;

    check[u] = true;
    int i;
    for(i=0;i<a[u].size();i++){
        topologicalSort(a,a[u][i],check);
    }

    st.push(u);

    return;
}

int main(){
    int i,s,t,V,E;

    scanf("%d %d",&V,&E);
    vector<int> a[10000];
    bool check[10000];

    for(i=0;i<V;i++){
        check[i] = false;
    }

    for(i=0;i<E;i++){
        scanf("%d %d",&s,&t);
        a[s].push_back(t);
    }

    for(i=0;i<V;i++){
        topologicalSort(a,i,check);
    }

    while(!st.empty()){
        printf("%d\n",st.top());
        st.pop();
    }

    return 0;
}
