#include <cstdio>

int combi(int n, int k) {
  if (n == k || k == 0)
    return 1;
  else {
    return combi(n - 1, k - 1) + combi(n - 1, k);
  }
}

int num[300];//num[l] is the number of line whose length is l[cm].
int usex[300];
int L;

typedef struct{
    int one;
    int two;
    int three;
}hoge;

hoge mult(int n, hoge ob){
    ob.one = n * ob.one;
    ob.two = n * ob.two;
    ob.three = n * ob.three;
    return ob;
}

hoge plus(hoge ob1, hoge ob2){
    hoge tmp;
    tmp.one = ob1.one + ob2.one;
    tmp.two = ob1.two + ob2.two;
    tmp.three = ob1.three + ob2.three;
    return tmp;
}

hoge makez(int x, int y){
    hoge tmp;
    tmp.one = 0;
    tmp.two = 0;
    tmp.three = 0;

    int z = L - x - y;

    if(x==z)tmp.three++;
    else if(x==y||y==z)tmp.two++;
    else tmp.one++;
    return tmp;
}

hoge makey(int x, int making, int l){
    hoge tmp;
    tmp.one = 0;
    tmp.two = 0;
    tmp.three = 0;

    for(int i=0;i<=num[l]-usex[l];i++){
        if((making + i*l)<x){
            tmp = mult(combi(num[l]-usex[l],i) , plus(tmp,makey(x,making+i*l,l+1)));
        }else if((making + i*l)<(L-x-(making + i*l))){
            tmp = mult(combi(num[l]-usex[l],i) , plus(tmp,makez(x,making+i*l)));
        }else{
            break;
        }
    }

    return tmp;
}

hoge makex(int x,int making, int l){
    hoge tmp;
    tmp.one = 0;
    tmp.two = 0;
    tmp.three = 0;

    if(making+l>x)return tmp;

    for(int i=0;i<=num[l];i++){
        usex[l] = i;
        if((making + i*l)<x){
            tmp = mult(combi(num[l],i) , plus(tmp,makex(x,making+i*l,l+1)));
        }else if((making + i*l)==x){
            tmp = mult(combi(num[l],i) , plus(tmp,makey(x,0,1)));
        }else{
            break;
        }
    }
    usex[l] = 0;

    return tmp;
}

int main(void){
    int i,n,a;
    L=0;
    scanf("%d",&n);
    for(i=0;i<300;i++){
        num[i] = 0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&a);
        num[a]++;
        L += a;
    }


    hoge tmp;
    tmp.one = 0;
    tmp.two = 0;
    tmp.three = 0;
    for(int x=1;x<L;x++){
        tmp = plus(tmp,makex(x,0,1));
    }

    printf("%d\n",tmp.one);
    printf("%d\n",tmp.two);
    printf("%d\n",tmp.three);
    printf("%d\n",tmp.one*6 + tmp.two*3 + tmp.three);
    return 0;
}
