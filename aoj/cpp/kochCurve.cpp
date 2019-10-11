#include <cstdio>
#include <cmath>

class point{
    double x;
    double y;
public:
    point(double a, double b){x=a;y=b;}
    point(){x=0;y=0;}
    point operator+(point ob2);
    point operator-(point ob2);
    point operator/(double d);
    point rot(point p, double theta);
    void print(){printf("%f %f\n",x,y);}
};

point point::operator+(point ob2){
    point tmp;
    tmp.x = x + ob2.x;
    tmp.y = y + ob2.y;
    return tmp;
}

point point::operator-(point ob2){
    point tmp;
    tmp.x = x - ob2.x;
    tmp.y = y - ob2.y;
    return tmp;
}

point point::operator/(double d){
    point tmp;
    tmp.x = x / d;
    tmp.y = y / d;
    return tmp;
}

point point::rot(point p, double theta){
    point tmp;
    tmp.x = p.x + cos(theta) * (x - p.x) - sin(theta) * (y - p.y);
    tmp.y = p.y + sin(theta) * (x - p.x) + cos(theta) * (y - p.y);
    return tmp;
}

void recursion(double n, point p, point q){
    if(n==0)return;

    point r, s, t;

    r = p + (q-p)/3;
    t = q + (p-q)/3;
    s = t.rot(r,M_PI/3);

    recursion(n-1,p,r);
    r.print();
    recursion(n-1,r,s);
    s.print();
    recursion(n-1,s,t);
    t.print();
    recursion(n-1,t,q);

    return;
}

int main(void){
    int n;
    scanf("%d",&n);
    point p(0,0), q(100,0);
    p.print();
    recursion(n, p, q);
    q.print();
    return 0;
}
