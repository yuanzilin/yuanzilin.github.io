#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct circle{
    int l,r;
    bool operator < (const circle a) const{
        if(l==a.l) return r<a.r;
        else
            return l<a.l;
    }
}circles[50001];

int n,i,x,r,cnt;
int search(int,int,int);

int main()
{
    while(~scanf("%d",&n)){
        cnt=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&x,&r);
            circles[i].l=x-r;
            circles[i].r=x+r;
        }
        sort(circles,circles+n);
        for(i=0;i<n-1;i++)
            cnt+=n-search(i+1,n-1,circles[i].r+1);
        printf("%d\n",cnt);
    }
}

int search(int low,int high,int key)
{
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(circles[mid].l>=key)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}