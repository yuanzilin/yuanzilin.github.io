#include <iostream>
#include <algorithm>
#define maxnum 10005

int n;
long long a[maxnum];
using namespace std;

int main()
{
    while (~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%lld",a+i);
        sort(a,a+n);
        long long mul=1,sum=0;
        for(int i=0;i<n;i++){
            mul=a[i]*(n-i-1);
            sum+=mul;
        }
        printf("%lld\n",sum);
    }
}
