#include <cstdio>
#include <list>
using namespace std;

int main(){
    list<char> l;

    l.push_front('b');
    l.push_back('c');
    l.push_front('a');

    printf("%c", l.front());
    printf("%c", l.back());

    l.pop_front();
    l.push_back('d');

    printf("%c", l.front());
    printf("%c", l.back());

    printf("\n");

    return 0;
}
