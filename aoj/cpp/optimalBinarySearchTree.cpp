#include <cstdio>
#include <cstdlib>

typedef struct node_{
    double probability;
    bool isDummy;
    struct node_* left;
    struct node_* right;
}node;

node* leftRotate(node* nd){
    node* tmp = nd->right;
    nd->right = tmp->left;
    tmp->left = nd;
    return tmp;
}

node* rightRotate(node* nd){
    node* tmp = nd->left;
    nd->left = tmp->right;
    tmp->right = nd;
    return tmp;
}

double calcCost(node* nd, int d){
    if(nd==NULL)return 0;
    return (d+1)*nd->probability + calcCost(nd->left,d+1) + calcCost(nd->right,d+1);
}

double calcProb(node* nd){
    if(nd==NULL)return 0;
    return nd->probability + calcProb(nd->left) + calcProb(nd->right);
}

node* obst(node* nd){
    if(nd->isDummy)return nd;
    nd->left = obst(nd->left);
    nd->right = obst(nd->right);

    double diff1, diff2;

    if(nd->left->isDummy){
        if(!(nd->right->isDummy)){
            diff1 = nd->probability + nd->left->probability - nd->right->probability - calcProb(nd->right->right);
            if(diff1<0)nd = obst(leftRotate(nd));
        }
    }else{
        if(nd->right->isDummy){
            diff2 = nd->probability + nd->right->probability - nd->left->probability - calcProb(nd->left->left);
            if(diff2<0)nd = obst(rightRotate(nd));
        }else{
            diff1 = nd->probability + calcProb(nd->left) - nd->right->probability - calcProb(nd->right->right);
            diff2 = nd->probability + calcProb(nd->right) - nd->left->probability - calcProb(nd->left->left);
            if(diff1<0){
                if(diff2<diff1)nd = obst(rightRotate(nd));
                else nd = obst(leftRotate(nd));
            }else{
                if(diff2<0)nd = obst(rightRotate(nd));
            }
        }
    }

    return nd;
}

node* init(double *p, double *q, int n){
    node *tmp1, *tmp2, *tmp3;

    tmp1 = (node *)malloc(sizeof(node));
    tmp1->probability = q[n];
    tmp1->isDummy = true;
    tmp1->left = NULL;
    tmp1->right = NULL;

    int i;
    for(i=n;i>0;i--){
        tmp3 = tmp1;

        tmp2 = (node *)malloc(sizeof(node));
        tmp2->probability = q[i-1];
        tmp2->isDummy = true;
        tmp2->left = NULL;
        tmp2->right = NULL;

        tmp1 = (node *)malloc(sizeof(node));
        tmp1->probability = p[i];
        tmp1->isDummy = false;
        tmp1->left = tmp2;
        tmp1->right = tmp3;
    }

    return tmp1;
}

int main(){
    int i,n;
    scanf("%d",&n);
    double *p = (double *)malloc(sizeof(double)*(n+1));
    double *q = (double *)malloc(sizeof(double)*(n+1));
    for(i=1;i<=n;i++)scanf("%lf",p+i);
    for(i=0;i<=n;i++)scanf("%lf",q+i);
    node* root = init(p,q,n);

    root = obst(root);
    root = obst(root);

    printf("%lf\n",calcCost(root,0));
    return 0;
}
