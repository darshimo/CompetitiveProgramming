#include <cstdio>
#include <vector>
using namespace std;

typedef struct node_{
    int key;
    int x[2];
    struct node_ *left;
    struct node_ *right;
}node;

vector<node> V;
vector<int> ans;

bool ascX(const node& left, const node& right){
    return left.x[0] != right.x[0] ? left.x[0] < right.x[0] : left.x[1] < right.x[1];
}

bool ascY(const node& left, const node& right){
    return left.x[1] != right.x[1] ? left.x[1] < right.x[1] : left.x[0] < right.x[0];
}

bool (*asc[2])(const node& left, const node& right) = {ascX,ascY,};

node *make2Dtree(int left, int right, char d){
    if(left>=right){
        return NULL;
    }
    int mid = (left + right)/2;
    sort(V.begin()+left, V.begin()+right, asc[d]);
    node *p = &V[mid];
    p->left = make2Dtree(left, mid, (d+1)%2);
    p->right = make2Dtree(mid+1, right, (d+1)%2);
    return p;
}

void find(node *root, int *sx, int *tx, char d){
    if(root==NULL)return;
    int x[2] = {root->x[0], root->x[1],};

    if(sx[0] <= x[0] && x[0] <= tx[0] && sx[1] <= x[1] && x[1] <= tx[1])ans.push_back(root->key);

    if(sx[d] <= x[d])find(root->left, sx, tx, (d+1)%2);
    if(x[d] <= tx[d])find(root->right, sx, tx, (d+1)%2);
}

int main(){
    int i,j,n,q,x,y,sx[2],tx[2];
    node tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        tmp.key = i;
        tmp.x[0] = x;
        tmp.x[1] = y;
        V.push_back(tmp);
    }
    node* root;
    root = make2Dtree(0, n, 0);

    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d %d %d %d",sx,tx,sx+1,tx+1);
        ans.clear();
        find(root,sx,tx,0);
        sort(ans.begin(), ans.end());
        for(j=0;j<ans.size();j++)printf("%d\n",ans[j]);
        printf("\n");
    }

    return 0;
}
