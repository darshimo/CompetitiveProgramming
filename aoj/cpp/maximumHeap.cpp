#include <cstdio>

void maxHeapify(int *a, int i, int h){
    int l = i*2;
    int r = i*2+1;

    int largest, tmp;
    if(l<=h and a[l]>a[i])largest = l;
    else largest = i;
    if(r<=h and a[r]>a[largest])largest = r;

    if(largest != i){
        tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        maxHeapify(a, largest, h);
    }else return;
}

void buildMaxHeap(int *a, int h){
    int i;
    for(i=h/2;i>0;i--)maxHeapify(a,i,h);
}

int main(){
    int i, h;
    scanf("%d",&h);
    int a[h+1];
    for(i=1;i<=h;i++)scanf("%d",a+i);
    buildMaxHeap(a, h);
    for(i=1;i<=h;i++)printf(" %d",a[i]);
    printf("\n");
    return 0;
}
