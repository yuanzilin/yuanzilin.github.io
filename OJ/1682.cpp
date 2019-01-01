#include <iostream>
#include <cstring>
#define maxm 105
#define maxt 10005

using namespace std;

int m,s,t;
int dp[maxm][maxt];

int count(int i,int j){
    if(!j)
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i>=10)
        return dp[i][j]=count(i-9,j-1)+60;
    return dp[i][j]=max(count(i+1,j-1)+17,count(i+5,j-1));
}

int find(int key)
{
    int l=0,r=t;
    while(l<=r){
        int mid=(l+r)>>1;
        if(count(m,mid)>=key)
            r=mid-1;
        else
            l=mid+1;
    }
    return l;
}

int main()
{
    memset(dp,-1,sizeof dp);
    while (~scanf("%d%d%d",&m,&s,&t)){
        int im=m,is=s,it=t;
        while (m>=10&&s>0&&t){
            m-=9;
            s-=60;
            t--;
        }
        if(s<=0)
            printf("Yes\n%d\n",it-t);
        else if(count(m,t)>=s)
            printf("Yes\n%d\n",it-t+find(s));
        else
            printf("No\n%d\n",count(m,t)+is-s);
    }
}