#include<iostream>
#include <cstring>
#include <queue>
#define inf 10000
#define N 20000
#define M 505

using namespace std;

struct Edge{
    int u,v,next,f;
}G[N];
int tot=0,n,len,s,t,ans;
int head[N],a[M],dp[M];
int level[100*M];

void addedge(int u,int v,int f){
    G[tot].u=u;G[tot].v=v;G[tot].f=f;G[tot].next=head[u];head[u]=tot++;
    G[tot].u=v;G[tot].v=u;G[tot].f=0;G[tot].next=head[v];head[v]=tot++;
}

bool bfs(int s,int t){
    memset(level,0,sizeof(level));
    level[s]=1;
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==t)
            return true;
        for(int i=head[u];i!=-1;i=G[i].next){
            int v=G[i].v,f=G[i].f;
            if(level[v]==0&&f){
                q.push(v);
                level[v]=level[u]+1;
            }

        }
    }

    return false;
}

int dfs(int u,int maxf,int t){
    if (u==t)
        return maxf;
    int rat=0;
    for (int i=head[u];i!=-1&&rat<maxf;i=G[i].next){
        int v=G[i].v;
        int f=G[i].f;
        if (level[v]==level[u]+1&&f){
            int Min=min(maxf-rat,f);
            f=dfs(v,Min,t);
            G[i].f-=f;G[i^1].f+=f;rat+=f;
        }
    }
    if (!rat)
        level[u]=N;
    return rat;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),dp[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1);//如果题目说的是不下降、非严格递增，a[j]和a[i]的关系应该是小于等于
    for(int i=1;i<=n;i++)
        len=max(len,dp[i]);
    printf("%d\n",len);

    s=0;t=5000;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
        if(dp[i]==1)
            addedge(s,i,1);
    for(int i=1;i<=n;i++)
        if(dp[i]==len)
            addedge(i+n,t,1);
    for(int i=1;i<=n;i++)
        addedge(i,i+n,1);

    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[j]<a[i]&&dp[j]+1==dp[i])//如果题目说的是不下降、非严格递增，a[j]和a[i]的关系应该是小于等于
                addedge(j+n,i,1);
    while(bfs(s,t))
        ans+=dfs(s,inf,t);
    printf("%d\n",ans);

    addedge(1,1+n,inf);
    addedge(s,1,inf);
    if(dp[n]==len)
        addedge(n,n*2,inf),addedge(n*2,t,inf);
    while(bfs(s,t))
        ans+=dfs(s,inf,t);
    printf("%d\n",ans);
    return 0;
}