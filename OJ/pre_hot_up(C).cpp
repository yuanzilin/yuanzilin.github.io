#include <iostream>
#include <cstring>
#define maxn 3001200

using namespace std;

int n,cnt,i,j;
bool flag[50000001];
int prime[maxn];

int Prime(int);
int search(int);

int main()
{
    Prime(50000000);
    while(cin>>n)
        cout<<search(n)<<endl;
}

int Prime(int n)
{
    cnt=0;
    memset(flag,1,sizeof(flag));
    for(i=2;i<=n;i++){
        if(flag[i])
            prime[cnt++]=i;
        for(j=0;j<cnt&&i*prime[j]<=n;j++){
            flag[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}
int search(int n)
{
    int mid;
    int low=0,high=cnt-1;
    if(n==1)
        return 0;
    while(low<=high){
        mid=(low+high)/2;
        if(high==low)
            return low+1;
        if(prime[mid]<n){
            low=mid+1;
            if(prime[low]>n)
                return low;
        }
        else if(prime[mid]>n){
            high=mid-1;
            if(prime[high]<n)
                return high+1;
        }
        else
            return mid+1;

    }
}