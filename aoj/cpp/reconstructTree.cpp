#include <cstdio>

typedef struct tree_{
    int parent;
    int left;
    int right;
}tree;

void postorder(tree *node, int id){
    if(node[id].left!=-1){
        postorder(node, node[id].left);
        printf(" ");
    }
    if(node[id].right!=-1){
        postorder(node, node[id].right);
        printf(" ");
    }
    printf("%d",id);
}

int reconstruct(int *pre, int *in, tree *node, int n){
    if(n==0)return -1;
    int root = pre[0];
    int n1, n2;
    for(n1=0;n1<n;n1++){
        if(in[n1]==root)break;
    }
    n2 = n - n1 - 1;
    node[root].left = reconstruct(pre+1, in, node, n1);
    node[root].right = reconstruct(pre+1+n1, in+1+n1, node, n2);
    return root;
}

int main(){
    int i, n;
    scanf("%d",&n);
    int pre[n];
    int in[n];
    tree node[n];
    for(i=0;i<n;i++)scanf("%d",pre+i);
    for(i=0;i<n;i++)scanf("%d",in+i);
    int root = reconstruct(pre, in, node, n);
    postorder(node, root);
    printf("\n");
    return 0;
}
