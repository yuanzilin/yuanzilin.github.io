#include <iostream>
#define mode 100007
typedef long long ll;

using namespace std;

ll inv(ll a,ll MOD){
    if(a==1)
        return 1;
    return inv(MOD%a,MOD)*(MOD-MOD/a)%MOD;
}

ll T,n;

int main()
{
    //std::cout<<inv(24,mode);
    long long  ans;
    for(scanf("%lld",&T);T--;){
        scanf("%lld",&n);
            if(n==1)
                ans=1;
            if(n==2)
                ans=2;
            if(n==3)
                ans=4;
            if(n==4)
                ans=8;
            if(n>4){
                ans=n*(-6+n+mode)%mode;
               // printf("ans=%lld\n",ans);
                ans=n*(23+ans)%mode;
                //printf("ans=%lld\n",ans);
                ans=n*(-18+ans+mode)%mode;
                //printf("ans=%lld\n",ans);
                ans=(24+ans)%mode;
                //printf("ans=%lld\n",ans);
                ans=(ans*inv(24,mode))%mode;
            }
        printf("%lld\n",ans);
    }
}