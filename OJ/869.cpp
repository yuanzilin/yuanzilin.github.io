#include <iostream>

using namespace std;

int n,x,y,t;
long long an[10005],copyan[10005],cnt;
void merge(long long [],int,int,int);
void merge_sort(long long [],int,int);

int main()
{
    int i;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)
            scanf("%lld",an+i);
        scanf("%d",&t);
        while(t--){
            for(i=0;i<n;i++)
                copyan[i]=an[i];
            scanf("%d%d",&x,&y);
            cnt=0;
            if(x>y) swap(x,y);
            merge_sort(copyan,x,y);
            printf("%lld\n",cnt);
        }
    }
}

void merge(long long a[],int left,int mid,int right)
{
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    long long L[n1]={0},R[n2]={0};
    for(i=0;i<n1;i++)
        L[i]=a[left+i];
    for(j=0;j<n2;j++)
        R[j]=a[mid+j+1];
    for(i=0,j=0;i<n1;i++){
        while(j<n2&&L[i]>R[j]*2)
            j++;
        cnt+=j;
    }
    i=0,j=0;
    for(k=left;k<=right&&i<n1&&j<n2;k++){
        if(L[i]<=R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
    while(i-n1<0)
        a[k++]=L[i++];
    while(j-n2<0)
        a[k++]=R[j++];
}

void merge_sort(long long a[],int left,int right)
{
    int mid;
    if(left-right<0){
        mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}