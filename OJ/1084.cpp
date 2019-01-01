//输入完成后，总时间肯定在[1,maxtime]之间，所以可以用二分
//对于每个mid值，我们设在mid时间内可以完成。那么对于每个大于mid值的c[i]，它的体力流失由两部分组成，先有s秒被特殊攻击，然后余下时间可以让它被普通攻击至生命值为0
//即特殊攻击流失的生命值为ks,普通攻击流失的生命值为mid-s，至于为什么是mid-s，体力到达这个值后，如果路明非继续攻击它，就会在时间用完前该龙鳞就被打碎了，
// 而在mid-s时间内，本来可以由别的英雄攻击该龙鳞，路明非转而去攻击别的生命值大的龙鳞。
//而为什么只需要计算特殊攻击次数和，是因为我们在特殊攻击某一块龙鳞时，其它龙鳞正在遭受普通攻击把所有特殊攻击次数加起来后其实也就是承受攻击的时间之和
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define maxnum 100005
typedef long long ll;

using namespace std;

int n,k;
int c[maxnum];

int main()
{
    while(~scanf("%d%d",&n,&k)){
        int ans=0;
        ll cnt=0,s=0;
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        sort(c,c+n);
        int maxtime=c[n-1];
        if(k==1){
            printf("%d\n",maxtime);
            continue;
        }

        int l=1,r=maxtime;
        while(l<=r){
            cnt=0;
            int mid=(l+r)>>1;
            for(int i=0;i<n;i++){
                if(c[i]>mid){
                    s=ceil(1.0*(c[i]-mid)/(k-1));
                    cnt+=s;
                }
            }
            if(cnt>mid)//说明设定的时间太短，需要增加
                l=mid+1;
            else//这里隐含的条件是cnt<=mid，说明这时候的mid值是可以接受的，已经找到了一个时间值。所以有ans=mid。但是不一定是最小的，所以还要继续r=mid-1；
                // 另外由于可能下一次就不符合了，所一个符合的值。以ans=mid，先要保存
                r=mid-1,ans=mid;
        }
        printf("%d\n",ans);
    }

}
