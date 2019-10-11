#include <cstdio>
#include <cstdlib>

typedef struct node_{
    int key;
    int priority;
    struct node_* left;
    struct node_* right;
    struct node_* parent;
}node;

node* rightRotate(node* t){
    node* s = t->left;
    if(s->right!=NULL)s->right->parent = t;
    t->left = s->right;
    s->parent = t->parent;
    s->right = t;
    t->parent = s;
    return s;
}

node* leftRotate(node* t){
    node* s = t->right;
    if(s->left!=NULL)s->left->parent = t;
    t->right = s->left;
    s->parent = t->parent;
    s->left = t;
    t->parent = s;
    return s;
}

node* insert(node* nd, node* parent, int k, int p){
    if(nd==NULL){
        nd = (node *)malloc(sizeof(node));
        nd->key = k;
        nd->priority = p;
        nd->left = NULL;
        nd->right = NULL;
        nd->parent = parent;
    }else if(k<nd->key){
        nd->left = insert(nd->left,nd,k,p);
        if(p>nd->priority)nd = rightRotate(nd);
    }else if(k>nd->key){
        nd->right = insert(nd->right,nd,k,p);
        if(p>nd->priority)nd = leftRotate(nd);
    }
    return nd;
}

node* find(node* nd, int k){
    if(nd==NULL)return nd;
    else if(k < nd->key)return find(nd->left,k);
    else if(k > nd->key)return find(nd->right,k);
    else return nd;
}

node* _del(node* nd){
    if(nd==NULL)return NULL;
    node* tmp;
    if(nd->left==NULL){
        if(nd->right==NULL){
            tmp = NULL;
            free(nd);
        }else{
            tmp = leftRotate(nd);
            tmp->left = _del(tmp->left);
        }
    }else{
        if(nd->right==NULL){
            tmp = rightRotate(nd);
            tmp->right = _del(tmp->right);
        }else{
            if(nd->left->priority<nd->right->priority){
                tmp = leftRotate(nd);
                tmp->left = _del(tmp->left);
            }else{
                tmp = rightRotate(nd);
                tmp->right = _del(tmp->right);
            }
        }
    }
    return tmp;
}

node* del(node* nd, int k){
    if(nd==NULL)return nd;
    else if(k < nd->key)nd->left = del(nd->left,k);
    else if(k > nd->key)nd->right = del(nd->right,k);
    else nd = _del(nd);
    return nd;
}

void preorder(node* nd){
    if(nd==NULL)return;
    printf(" %d",nd->key);
    preorder(nd->left);
    preorder(nd->right);
}

void inorder(node* nd){
    if(nd==NULL)return;
    inorder(nd->left);
    printf(" %d",nd->key);
    inorder(nd->right);
}

int main(){
    int i, m, k, p;
    char command[7];
    node* tmp;
    node* root = NULL;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%s",command);
        switch(command[0]){
        case 'i'://insert
            scanf("%d %d",&k,&p);
            root = insert(root, NULL, k, p);
            break;
        case 'f'://find
            scanf("%d",&k);
            if(find(root, k)!=NULL)printf("yes\n");
            else printf("no\n");
            break;
        case 'd'://del
            scanf("%d",&k);
            root = del(root, k);
            break;
        case 'p'://pirnt
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
            break;
        default:
            perror("error\n");
            return 1;
            break;
        }
    }
    return 0;
}
