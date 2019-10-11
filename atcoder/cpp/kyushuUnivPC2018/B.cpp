#include <cstdio>

bool check(long a, long b, long c){
    if(c%2)return false;

    if(a%2){
        if(b>=10){
            b-=10;
        }else if(c>=100-b*10){
            c-=100-b*10;
            b=0;
        }else{
            return false;
        }
    }

    if(b%2){
        if(c>=10){
            return true;
        }else{
            return false;
        }
    }

    return true;
}

int main(){
    int i,q;
    long a,b,c;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%ld %ld %ld",&a,&b,&c);
        if(check(a,b,c))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
