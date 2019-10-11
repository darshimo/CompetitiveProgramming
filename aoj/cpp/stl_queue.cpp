#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int main(){
    queue<string> q;

    q.push("red");
    q.push("yellow");
    q.push("yellow");
    q.push("glue");

    printf("front: %s\n", q.front().c_str());
    q.pop();

    printf("front: %s\n", q.front().c_str());
    q.pop();

    printf("front: %s\n", q.front().c_str());
    q.pop();

    q.push("green");

    printf("front: %s\n", q.front().c_str());
    q.pop();

    printf("front: %s\n", q.front().c_str());

    return 0;
}
