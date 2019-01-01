#include <iostream>
#include <cstring>
#include <algorithm>
#define maxnum 100005

using namespace std;

int M,K,S;
long long  mc[maxnum],ml[maxnum],kw[maxnum],kr[maxnum],dp[maxnum];
struct water{
    long long c;
    long long l;
    double ave;
    bool operator <(const water a) const{
        return ave>a.ave;
    }
}w[maxnum];

void zeropack(){
    for(int i=0;i<K;i++){
        for(long long j=S;j>=kw[i];j--){
            if(dp[j-kw[i]]+kr[i]>dp[j]&&dp[j-kw[i]]!=-1)
                dp[j]=dp[j-kw[i]]+kr[i];
        }
    }
}

double fracpack(int sum,long long tmpsum)
{

    int i;
//    for(i=0;i<M;i++){
//        printf("w[%d].c=%d,"
//               "w[%d].l=%d\n",i,w[i].c,i,w[i].l);
//    }
    long long value=tmpsum;
    for( i=0;i<M&&w[i].c<=sum;i++){
        value+=w[i].l;
        sum-=w[i].c;
        //printf("value=%lld\n",value);
    }
//    printf("i=%d\n",i);
//    printf("value=%lld\n",value);
    double ans=(double)value;
    if(i<M){
        ans+=(double)sum*w[i].l/w[i].c;
    }
    //printf("ans=%.1lf\n",ans);
    return ans;
}

int main()
{
    while (~scanf("%d%d%d",&M,&K,&S)){
        memset(dp,-1, sizeof(dp));
        dp[0]=0;
        for(int i=0;i<M;i++){
            scanf("%lld%lld",&w[i].c,&w[i].l);
            w[i].ave=(double)w[i].l/w[i].c;
        }
        for(int i=0;i<K;i++)
            scanf("%lld%lld",kw+i,kr+i);

        sort(w,w+M);
        zeropack();
        long long max1=0;
        int flag1=0;
        for(int i=1;i<=S;i++){
        //   printf("dp[%d]=%lld\n",i,dp[i]);
            if(max1<dp[i]){
                max1=dp[i];
                flag1=i;
                //cout<<"max1="<<max1<<endl;
            }
        }
        int newS=S-flag1;
        //cout<<newS<<endl;
        printf("%.1lf\n",fracpack(newS,max1));
    }
}