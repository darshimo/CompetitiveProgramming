#include <cstdio>
#include <climits>
using namespace std;

int main(){
    int n, i, r;
    int min = INT_MAX;
    int profit = INT_MIN;
    scanf("%d",&n);
    scanf("%d",&min);
    for(i=0;i<n-1;i++){
        scanf("%d",&r);
        if(r-min>profit)profit=r-min;
        if(r<min)min=r;
    }
    printf("%d\n",profit);
    return 0;
}
