#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class queue{
    int *time;
    char (*name)[11];
    int head, tail, size;
public:
    queue(int n){
        size = n;
        time = new int [size];
        name = new char [size][11];
        head = 0;
        tail = 0;
    };
    bool isEmpty(){
        return head==tail;
    };
    bool isFull(){
        return tail==head+size;
    };
    int &enqueue(char *s);
    int dequque(char *s);
};

int &queue::enqueue(char *s){
    if(isFull()){
        printf("queue is full.\n");
        exit(1);
    }
    strcpy(name[(tail)%size],s);
    tail = (tail+1) % (2*size);
    return time[(tail-1)%size];
}

int queue::dequque(char *s){
    if(isEmpty()){
        printf("queue is empty.\n");
        exit(1);
    }
    strcpy(s,name[(head)%size]);
    head = (head+1) % (2*size);
    return time[(head-1)%size];
}

int main(){
    int time, i, n, q;
    char name[11];
    int total = 0;
    scanf("%d",&n);
    scanf("%d",&q);
    queue ob(n);
    for(i=0;i<n;i++){
        scanf("%s %d",name,&time);
        ob.enqueue(name) = time;
    }
    while(!ob.isEmpty()){
        time = ob.dequque(name);
        if(time>q){
            ob.enqueue(name) = time-q;
            total += q;
        }else{
            total += time;
            printf("%s %d\n",name,total);
        }
    }
    return 0;
}
