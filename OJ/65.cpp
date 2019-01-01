#include <iostream>
#include <queue>
#include <algorithm>
#define maxn 100005

using namespace std;

int n,ai[maxn],k;

int main()
{
    while(~scanf("%d",&n)){
        int t=0;
        for(int i=1;i<=n;i++)
            scanf("%d",ai+i);

        scanf("%d",&k);

        sort(ai+1,ai+n+1);

        while(ai[n]>0){
            for(int i=1;i<=n-1;i++)
                ai[i]--;
            ai[n]-=k;
            sort(ai+1,ai+n+1);
            t++;
        }
        printf("%d\n",t);
    }
}