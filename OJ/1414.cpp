#include <iostream>
#define maxsize 1000001
typedef long long ll;
using namespace std;

int n,T,Ln,Rn,i;
ll an[maxsize],cnt;

void merge(ll [],int,int,int);
void merge_sort(ll [],int ,int);
int main()
{
    for(scanf("%d",&T);T--;){
        scanf("%d%d%d",&n,&Ln,&Rn);
        cnt=0;
        for(i=0;i<n;i++)
            scanf("%lld",an+i);
        merge_sort(an,0,n-1);
        printf("%lld\n",cnt);
    }
}
void merge(ll a[],int left,int mid,int right)
{
    int newL,newR;
    int n1=mid-left+1;
    int n2=right-mid;
    int i,j,k;
    ll L[n1]={0},R[n2]={0};
    for(i=0;i<n1;i++)
        L[i]=a[left+i];
    for(j=0;j<n2;j++)
        R[j]=a[mid+1+j];
    newL=0,newR=0;
    for(i=0;i<n2;i++){
        for(j=newL;j<n1;j++){
            if(R[i]-L[j]>=Ln)
                newL++;
            else
                break;
        }
        for(j=newR;j<n1;j++){
            if(R[i]-L[j]>Rn)
                newR++;
            else
                break;
        }
        cnt+=newL-newR;
    }
    i=0,j=0;
    for(k=left;k<=right&&i<n1&&j<n2;k++){
        if(L[i]<R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}

void merge_sort(ll a[],int left,int right){
    int mid;
    if(left<right){
        mid=(left+right)>>1;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}