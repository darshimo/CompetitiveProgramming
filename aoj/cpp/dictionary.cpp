#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#define TABLE_SIZE 22369620

class Dic{
    bool *table;
    int converter(char *str);
public:
    Dic(){table=(bool *)malloc(sizeof(bool)*TABLE_SIZE);memset(table, 0, sizeof(bool)*TABLE_SIZE);}
    void insert(char *str){table[converter(str)] = true;}
    bool find(char *str){return table[converter(str)];}
};

int Dic::converter(char *str){
    int key = 0;
    int len = strlen(str);
    for(int i=0;i<len;i++){
        switch(str[i]){
        case 'A':
            key += pow(4,i);
            break;
        case 'C':
            key += 2 * pow(4,i);
            break;
        case 'G':
            key += 3 * pow(4,i);
            break;
        case 'T':
            key += 4 * pow(4,i);
            break;
        default:
            break;
        }
    }
    return key - 1;
}

int main(){
    int i, n;
    char str[13];
    int bs = 0;
    Dic d;
    scanf("%d",&n);
    bool ans[n];
    for(i=0;i<n;i++){
        scanf("%s",str);
        if(!strcmp(str,"insert")){
            scanf("%s",str);
            d.insert(str);
        }else if(!strcmp(str,"find")){
            scanf("%s",str);
            ans[bs] = d.find(str);
            bs++;
        }
    }
    for(i=0;i<bs;i++){
        if(ans[i])printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
