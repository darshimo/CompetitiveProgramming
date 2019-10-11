#include <cstdio>
#include <utility>
#include <climits>
using namespace std;

class node{
    int c;
    int h;
    node* p;
public:
    node(){c=0;h=0;p=NULL;}
    void incC(){c++;}
    void setHP(int height, node* parent){
        h = height;
        p = parent;
    }
    int getC(){return c;}
    pair<int,node*> getHP(){
        if(this->p==NULL)return make_pair(0, this);
        else{
            pair<int,node*> tmp = p->getHP();
            tmp.first += h;
            return tmp;
        }
    }
};

node ob[100000];

int diff(int x, int y){
    pair<int,node*> tmp1 = ob[x].getHP();
    pair<int,node*> tmp2 = ob[y].getHP();
    if(tmp1.second != tmp2.second)return INT_MAX;
    else return tmp2.first - tmp1.first;
}

void relate(int x, int y, int z){
    pair<int,node*> tmp1 = ob[x].getHP();
    pair<int,node*> tmp2 = ob[y].getHP();
    if(tmp1.second == tmp2.second)return;
    if(tmp1.second->getC() < tmp2.second->getC()){
        tmp1.second->setHP(tmp2.first - tmp1.first - z, tmp2.second);
    }else{
        tmp2.second->setHP(tmp1.first - tmp2.first + z, tmp1.second);
        if(tmp1.second->getC() == tmp2.second->getC()){
            tmp1.second->incC();
        }
    }
}

int main(){
    int i,n,q,com,x,y,z,tmp;
    scanf("%d %d",&n,&q);
    for(i=0;i<q;i++){
        scanf("%d",&com);
        if(com){
            scanf("%d %d",&x,&y);
            int tmp = diff(x,y);
            if(tmp==INT_MAX)printf("?\n");
            else printf("%d\n",diff(x,y));
        }else{
            scanf("%d %d %d",&x,&y,&z);
            relate(x,y,z);
        }
    }
    return 0;
}
