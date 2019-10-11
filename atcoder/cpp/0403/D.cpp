#include <stdio.h>
#include <stdlib.h>

#define L_SHRT 1
#define L_LONG 2
#define R_SHRT 3
#define R_LONG 4

int main(){
    int h,w,d;
    scanf("%d%d%d",&h,&w,&d);
    int i,j,k;
    int array[h*w][2];
    int (*p)[2] = &array[-1];
    int tmp;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%d",&tmp);
            p[tmp][0]=i;
            p[tmp][1]=j;
        }
    }
    int q,lr,min,type,mp_;
    scanf("%d",&q);
    int l[q],r[q],mp[q];
    for(i=0;i<q;i++){
        scanf("%d %d",&l[i],&r[i]);
        mp[i] = 0;
        lr = 0;
        min = h*w+1;
        tmp = 0;
        type = 0;
        for(j=0;j<i;j++){
            if(l[i]==l[j]&&r[i]==r[j])break;
            if(l[i]==l[j]){
                if(abs(r[i]-r[j])<min){
                    min=abs(r[i]-r[j]);
                    tmp = j;
                    if(r[i]>r[j])type=L_LONG;
                    else type=L_SHRT;
                }
            }
            if(r[i]==r[j]){
                if(abs(l[i]-l[j])<min){
                    min=abs(l[i]-l[j]);
                    tmp = j;
                    if(l[i]>l[j])type=R_SHRT;
                    else R_LONG;
                }
            }
        }
        if(j<i){
            mp[i]=mp[j];
        }else if(!type){
            for(k=l[i];k<r[i];k+=d){
                mp[i] += abs(p[k][0] - p[k+d][0]) + abs(p[k][1] - p[k+d][1]);
            }
        }else{
            mp_ = 0;
            switch(type){
                case L_LONG:
                for(k=r[j];k<r[i];k+=d){
                    mp_ += abs(p[k][0] - p[k+d][0]) + abs(p[k][1] - p[k+d][1]);
                }
                break;
                case L_SHRT:
                for(k=r[i];k<r[j];k+=d){
                    mp_ -= abs(p[k][0] - p[k+d][0]) + abs(p[k][1] - p[k+d][1]);
                }
                break;
                case R_LONG:
                for(k=l[i];k<l[j];k+=d){
                    mp_ += abs(p[k][0] - p[k+d][0]) + abs(p[k][1] - p[k+d][1]);
                }
                break;
                case R_SHRT:
                for(k=l[j];k<l[i];k+=d){
                    mp_ -= abs(p[k][0] - p[k+d][0]) + abs(p[k][1] - p[k+d][1]);
                }
                break;
                default:
                break;
            }
            mp[i] = mp[j] + mp_;
        }
    }
    for(i=0;i<q;i++){
        printf("%d\n",mp[i]);
    }
    return 0;
}
