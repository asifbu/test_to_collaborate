//ok
//ok
#include<stdio.h>
void merge(int L[],int R[],int l,int r, int arr[])
{
    int i,j,k;
    i=0;j=0;k=0;
    while(i<l && j<r)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<l)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<r)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int n)
{
    if(n<2)
        return;
    int mid=n/2,lsize,rsize,i;
    int left[mid+2],right[mid+2];
    for(i=0;i<mid;i++){
        left[i]=arr[i];
    }
    lsize=i;
    for(i=mid;i<(n);i++){
        right[i-mid]=arr[i];
    }
    rsize=n-lsize;
    mergesort(left,lsize);
    mergesort(right,rsize);
    merge(left,right,lsize,rsize,arr);
}
int main()
{
    int arr[1000]={0};
    int n,i,j,k;
    freopen("marge.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort(arr,n);
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
}
