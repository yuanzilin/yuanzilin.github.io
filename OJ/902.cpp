#include <iostream>
#include <cstring>
#define maxnum 50005
#define mode 1000007

using namespace std;

int n,i,j,ans;
int dp[maxnum][2];

int main()
{
    while(~scanf("%d",&n)){
        ans=0;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=1;i<350;i++){
            for(j=0;j<350;j++)
                dp[j][i&1]=0;
            for(j=i;j<=n;j++)
                dp[j][i&1]=(dp[j-i][i&1]+dp[j-i][(i-1)&1])%mode;
            ans=(ans+dp[n][i&1])%mode;
        }
        printf("%d\n",ans);
    }
}