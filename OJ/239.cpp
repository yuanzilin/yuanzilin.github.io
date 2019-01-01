#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxnum 1000005
typedef long long ll;

using namespace std;

typedef struct point{
    ll x,y;
}P;

P points[maxnum],stack[maxnum];
int n;

//算距离
ll dis(P a,P b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

//算方向
ll direc(P pi,P pj,P p0)
{
    return (p0.x-pi.x)*(p0.y-pj.y)-(p0.x-pj.x)*(p0.y-pi.y);
}

//重载比较函数
bool cmp(P a,P b)
{
    if(direc(a,b,points[1])>0)
        return true;
    if((!direc(a,b,points[1]))&&dis(b,points[1])>dis(a,points[1]))
        return true;
    return false;
}

//求解凸包并在其上求最远点对
ll do_it()
{
    int k=1;
    for(int i=2;i<=n;i++){
        if((points[k].y>points[i].y)||(points[k].y==points[i].y&&points[k].x>points[i].x))
            k=i;
    }
    P tmp;
    tmp=points[1];
    points[1]=points[k];
    points[k]=tmp;
    sort(points+2,points+n+1,cmp);
    stack[1]=points[1];
    stack[2]=points[2];
    int top=2;
    for(int i=3;i<=n;i++){
        while (top>=2&&direc(stack[top],points[i],stack[top-1])<=0)
            top--;
        stack[++top]=points[i];
    }
    
    ll ans=0;
    for(int i=1;i<=top;i++)
        for(int j=i+1;j<=top;j++)
        {
            ans=max(ans,dis(stack[i],stack[j]));
        }
    return ans;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&points[i].x,&points[i].y);
        printf("%lld\n",do_it());
    }
}