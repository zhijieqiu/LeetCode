#include <cstdio>
#include <algorithm>
using namespace std;

int partition(int arr[],int l,int r){
    int i=l,j = l+1,pivot = arr[l];
    for(;j<=r;j++){
        if(arr[j]<=pivot){
            swap(arr[i+1],arr[j]);
            i++;
        }
    }
    swap(arr[l],arr[i]);
    return i;
}
int search(int arr[],int l,int r,int k){
    if(l<r){
        int p = partition(arr,l,r);
        if(p==k)
            return arr[p];
        else if(p<k){
            return search(arr,p+1,r,k);
        }else
            return search(arr,l,p-1,k);
    }
    if(l==r)
        return arr[l];
    return -1;
}

int main()
{
    int val[1000010];
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",val+i);
    }
    printf("%d\n",search(val,1,n,k));
}
