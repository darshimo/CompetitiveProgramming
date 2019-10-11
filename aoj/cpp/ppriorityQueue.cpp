#include <cstdio>
#include <cstring>


int maxHeapify(int *a, int i, int h){
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
        return largest;
    }else return 0;
}

void heapUp(int *a, int h){
    int tmp = h;
    int hoge = 1;
    while(tmp>1 and hoge>0){
        tmp = tmp/2;
        hoge = maxHeapify(a,tmp,h);
    }
}

void heapDown(int *a, int h){
    int tmp=1;
    while(tmp>0){
        tmp = maxHeapify(a,tmp,h);
    }
}

int main(){
    int x;
    char cmd[8];
    int array[2000001];
    int tail=1;
    while(true){
        scanf("%s",cmd);
        if(strcmp(cmd,"insert")==0){
            scanf("%d",&x);
            array[tail]=x;
            tail++;
            heapUp(array, tail-1);
        }else if(strcmp(cmd,"extract")==0){
            printf("%d\n",array[1]);
            array[1] = array[tail-1];
            tail--;
            heapDown(array,tail-1);
        }else if(strcmp(cmd,"end")==0){
            break;
        }else return -1;
    }
    return 0;
}
