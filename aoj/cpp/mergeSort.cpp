#include <cstdio>
#include <climits>

int merge(int *A, int left, int mid, int right){
    int i, j;
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1];
    int R[n2+1];
    for(i=0;i<n1;i++)L[i]=A[left+i];
    for(i=0;i<n2;i++)R[i]=A[mid+i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
    return right - left;
}

int mergeSort(int *A, int left, int right){
    if(left+1>=right)return 0;
    int c = 0;
    int mid = (left + right)/2;
    c += mergeSort(A, left, mid);
    c += mergeSort(A, mid, right);
    c += merge(A, left, mid, right);
    return c;
}

int main(){
    int i, n, c;
    scanf("%d",&n);
    int s[n];
    for(i=0;i<n;i++)scanf("%d",s+i);
    c = mergeSort(s, 0, n);
    for(i=0;i<n;i++){
        printf("%d",s[i]);
        if(i<n-1)printf(" ");
        else printf("\n");
    }
    printf("%d\n",c);
    return 0;
}
