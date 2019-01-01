#include <iostream>

using namespace std;

int n,x,y,t,an[10005],copyan[10005],cnt;
void merge(int [],int,int,int);
void merge_sort(int [],int,int);

int main()
{
    int i;
    while(cin>>n){
        for(i=0;i<n;i++)
            cin>>an[i];
        cin>>t;
        while(t--){
            for(i=0;i<n;i++)
                copyan[i]=an[i];
            cin>>x>>y;
            cnt=0;
            merge_sort(copyan,x,y);
            cout<<cnt;
            cout<<"\n";
        }
    }
}

void merge(int a[],int left,int mid,int right)
{
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1]={0},R[n2]={0};
    for(i=0;i<n1;i++)
        L[i]=a[left+i];
    for(j=0;j<n2;j++)
        R[j]=a[mid+j+1];
    i=0,j=0;
    for(k=left;k<=right&&i<n1&&j<n2;k++){
        if(L[i]<=R[j])
            a[k]=L[i++];
        else{
            cnt+=n1-i;
            a[k]=R[j++];
        }
    }
    while(i-n1<0)
        a[k++]=L[i++];
    while(j-n2<0)
        a[k++]=R[j++];
}

void merge_sort(int a[],int left,int right)
{
    int mid;
    if(left-right<0){
        mid=(left+right)>>1;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}