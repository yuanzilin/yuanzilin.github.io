#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxnum 1000005
typedef long long ll;

using namespace std;

int T,n,l,r;
ll ans;
ll a[maxnum];

void merge_sort(int left,int right){
    int j;
    int lb=left,rb=left;
    int mid=(left+right)>>1;
    for(j=mid+1;j<=right;j++){
        lb=upper_bound(a+left,a+mid+1,a[j]-l)-a;
        rb=lower_bound(a+left,a+mid+1,a[j]-r)-a;
        ans+=lb-rb;
    }
}

void solve(int left,int right){
    int mid=(left+right)>>1;
    if(left<right){
        solve(left,mid);
        solve(mid+1,right);
        merge_sort(left,right);
    }
}

int main()
{
    for(scanf("%d",&T);T--;){
        scanf("%d%d%d",&n,&l,&r);
        ans=0;
        scanf("%lld",&a[1]);
        for(int i=2;i<=n;i++){
            scanf("%lld",&a[i]);
            a[i]+=a[i-1];
        }
        a[0]=0;
        solve(0,n);
        printf("%lld\n",ans);
    }
}