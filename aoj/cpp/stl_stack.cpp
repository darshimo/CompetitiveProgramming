#include <cstdio>
#include <stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(3);
    s.push(7);
    s.push(1);
    printf("size: %lu\n",s.size());

    printf("top: %d\n", s.top());
    s.pop();

    printf("top: %d\n", s.top());
    s.pop();

    printf("top: %d\n", s.top());

    s.push(5);

    printf("top: %d\n", s.top());
    s.pop();

    printf("top: %d\n", s.top());

    return 0;
}
