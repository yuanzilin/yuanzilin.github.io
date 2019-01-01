#include <iostream>
#define maxnum 1000005

int n;
long long a[maxnum];

int main()
{
    while (~scanf("%d",&n)){
        long long sum=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",a+i);
        for(int i=2;i<=n;i++){
            if(a[i]>a[i-1])
                sum+=a[i]-a[i-1];
        }
        printf("%lld\n",sum);
    }
}