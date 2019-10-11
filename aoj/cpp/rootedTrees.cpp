#include <cstdio>
#include <cstdlib>

typedef struct tree_{
    int parent;
    int depth;
    int noc;
    int *child;
}tree;

void setDepth(tree *node, int id, int depth){
    node[id].depth = depth;
    for(int i=0;i<node[id].noc;i++)setDepth(node,node[id].child[i],depth+1);
    return;
}

int main(){
    int i, j, n, id, k, c, root;
    scanf("%d",&n);
    tree node[n];
    for(i=0;i<n;i++)node[i].parent = -1;
    for(i=0;i<n;i++){
        scanf("%d %d",&id,&k);
        node[id].noc = k;
        node[id].child = (int *)malloc(sizeof(int)*k);
        for(j=0;j<k;j++){
            scanf("%d",&c);
            node[id].child[j]=c;
            node[c].parent=id;
        }
    }
    for(i=0;i<n;i++)if(node[i].parent==-1)break;
    if(i==n)return -1;
    root = i;
    setDepth(node, root, 0);
    for(id=0;id<n;id++){
        printf("node %d: parent = %d, depth = %d, ",id,node[id].parent,node[id].depth);
        if(node[id].parent==-1)printf("root, ");
        else if(node[id].noc==0)printf("leaf, ");
        else printf("internal node, ");
        printf("[");
        for(j=0;j<node[id].noc;j++){
            printf("%d",node[id].child[j]);
            if(j<node[id].noc-1)printf(", ");
        }
        printf("]\n");
    }
    return 0;
}
