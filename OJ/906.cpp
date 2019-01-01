#include <iostream>
#include <cstring>
#define maxnum 25

using namespace std;

int n;
string num;

inline long long ctoi(int i,int j){
    long long d=0;
    for(int k=i;k<=j;k++)
        d=d*10+num[k-1]-'0';
    return d;
}

int main()
{
    while (~scanf("%d",&n)){
        cin>>num;
        int len=num.size();
        long long dp[maxnum][15];
        memset(dp,0, sizeof(dp));
        dp[1][0]=num[0]-'0';
        for(int i=1;i<len;i++){
            dp[i+1][0]=dp[i][0]*10+num[i]-'0';
        }
        for(int k=1;k<=n;k++){
            for(int i=k+1;i<=len;i++){
                for(int j=k;j<i;j++){
                    if(dp[i][k]<dp[j][k-1]*ctoi(j+1,i)){
                        dp[i][k]=dp[j][k-1]*ctoi(j+1,i);
                    }
                }
            }
        }
        printf("%lld\n",dp[len][n]);
    }
}