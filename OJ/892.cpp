#include <cstdio>
#include <algorithm>

using namespace std;

const int maxsize=100001;
int a[maxsize],b[maxsize];
int special,i,n,len_a,len_b,sgn,ans;
int search(int [],int,int);

int main()
{
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        for(i=0;i<n;i++)
            scanf("%d",b+i);
        scanf("%d",&special);
        sort(a,a+n), sort(b,b+n);
        len_a=unique(a,a+n)-a,len_b=unique(b,b+n)-b;
        for(i=0;i<len_a;i++){
            sgn=search(b,len_b,special-a[i]);
            if(sgn>=0){
                ans=1;
                printf("%d %d\n",a[i],b[sgn]);
            }
        }
        if(!ans)
            printf("OTZ\n");
        puts("");
        sgn=-1,ans=0;
    }
}


int search(int a[],int sum,int item)
{
    int low=0,high=sum-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(item>a[mid])
            low=mid+1;
        else if(item<a[mid])
            high=mid-1;
        else
            return mid;
    }
    return -1;
}