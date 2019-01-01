#include <iostream>
#include <cstdio>
#define maxsize 1000001

using namespace std;

int n,t,input;
int ans[maxsize];

int main()
{
    int i,a1,a2,amax=0,amin=0;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",ans+1);
        for(i=2;i<=n;i++){
            scanf("%d",&input);
            ans[i]=input^ans[i-1];
        }
        scanf("%d",&t);
        while(t--){
            scanf("%d%d",&a1,&a2);
            amax=max(a1,a2);
            amin=min(a1,a2);
            printf("%d\n",ans[amin-1]^ans[amax]);
        }
    }
}