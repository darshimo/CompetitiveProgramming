#include <cstdio>
#include <algorithm>

typedef struct tree_{
    int parent;
    int left;
    int right;
    int depth;
    int height;
    int sibling;
}tree;

int height(tree *node, int id, int depth){
    if(id==-1)return -1;
    int l = node[id].left;
    int r = node[id].right;
    node[id].depth = depth;
    node[id].height = std::max(height(node, l, depth+1),height(node, r, depth+1)) + 1;
    return node[id].height;
}

int main(){
    int i, n, id, left, right;
    scanf("%d",&n);
    tree node[n];
    for(id=0;id<n;id++){
        node[id].parent = -1;
        node[id].sibling = -1;
    }
    for(i=0;i<n;i++){
        scanf("%d %d %d",&id,&left,&right);
        node[id].left = left;
        node[id].right = right;
        node[left].parent = id;
        node[right].parent = id;
        node[left].sibling = right;
        node[right].sibling = left;
    }
    int root;
    for(root=0;root<n;root++)if(node[root].parent==-1)break;
    if(root==n)return -1;
    int h = height(node, root, 0);
    int degree;
    for(id=0;id<n;id++){
        int degree = 0;
        if(node[id].left>=0)degree++;
        if(node[id].right>=0)degree++;
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",id,node[id].parent,node[id].sibling,degree,node[id].depth,node[id].height);
        if(node[id].parent == -1)printf("root\n");
        else if(node[id].left*node[id].right==1)printf("leaf\n");
        else printf("internal node\n");
    }
    return 0;
}
