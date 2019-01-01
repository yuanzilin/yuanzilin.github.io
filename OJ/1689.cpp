#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 100005

using  namespace std;

int n,ti,di;
struct fish{
    long long t,d;
    long double ave;
    bool operator <(const fish a)const{
        if(ave==a.ave)
            return t<a.t;
        return ave>a.ave;
    }
}f[maxn];

int main()
{
    long long sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&f[i].t,&f[i].d);
        f[i].ave=(long double)f[i].d/(long double)f[i].t;
    }
    long long sumall[maxn];
    memset(sumall,0,sizeof sumall);

    sort(f+1,f+n+1);
    sumall[n]=f[n].d;
    for(int i=n-1;i>=0;i--){
        sumall[i]+=f[i].d+sumall[i+1];
//        printf("%lld ",sumall[i]);
    }
//    puts("");
//    printf("%d\n",f[1].t);
//    for(int i=1;i<=n;i++){
//        printf("f[%d].t=%d,"
//               "f[%d].d=%d\n",i,f[i].t,i,f[i].d);
//    }
    for(int i=1;i<n;i++){
        long long tmp1=sumall[i+1];
        sum+=f[i].t*tmp1;
    }
    printf("%lld\n",sum);
}