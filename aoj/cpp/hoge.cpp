#include <random>
#include <stdio.h>
int main()
{
    std::random_device rnd;     // 非決定的な乱数生成器
    for (int i = 0; i < 10; ++i) {
        printf("%d\n",rnd()%100);
    }
    return 0;
}
