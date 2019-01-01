#include <iostream>
#include <cstring>
#define maxnum 20

using namespace std;

int n;
int h[maxnum],dp[maxnum];

int lis()
{
    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=1;
    }
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++){
            if(h[j]>h[i])
                dp[i]=max(dp[j]+1,dp[i]);
        }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }

    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",h+i);
    }
    printf("%d\n",lis());
}