//这道题的二三问有重叠的部分，所以需要分开构图
#include<iostream>
#include<cstring>
#include<queue>
#define maxn 1005
#define maxedge 200010
#define inf 0xffffff

using namespace std;

int cnt=1;
int n;
int S,T;
int len;
int depth[maxn],head[maxn],cur[maxn];
int a[maxn],dp[maxn];
struct edge{
    int to,w,last;
    edge(){}
    edge(int x,int y,int z){
        to=x,w=y,last=z;
    }
}e[maxedge];

int lis();
void add_edge(int,int ,int );
bool bfs();
int dfs();
int dinic();
void ans2();
void ans3();

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=1;
    }
    len=lis();
    printf("%d\n",len);

    S=0,T=2*n+1;

    ans2();

    ans3();
}

void ans2()
{
    memset(head,0,sizeof head);
    for(int i=1;i<=n;i++){
        add_edge(i,i+n,1);
        if(dp[i]==1)
            add_edge(S,i,1);
        if(dp[i]==len)
            add_edge(i+n,T,1);
        for(int j=1;j<i;j++)
            if(a[j]<a[i]&&dp[j]+1==dp[i])
                add_edge(j+n,i,1);
    }
    printf("%d\n",dinic());
}

void ans3()
{
    memset(head,0,sizeof head);
    cnt=1;
    for(int i=1;i<=n;i++){
        int flow=1;
        if(i==1||i==n)
            flow=inf;
        add_edge(i,i+n,flow);
        if(dp[i]==1)
            add_edge(S,i,flow);
        if(dp[i]==len)
            add_edge(i+n,T,flow);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)
            if(a[j]<a[i]&&dp[j]+1==dp[i])
                add_edge(j+n,i,1);
    }
    int tmp=dinic();
    tmp>=inf?printf("%d\n",n):printf("%d\n",tmp);//如果序列元素都是一样的，那么就存在多条容量为inf的增广路，就没法实现每次找通路流量均为1的目的了，所以这里需要比较一番。
}

int lis()
{
    int ans=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                dp[i]=max(dp[j]+1,dp[i]);
        ans=max(dp[i],ans);
    }
    return ans;
}

bool bfs()
{
    queue<int> q;
    q.push(S);
    memset(depth,-1,sizeof depth);
    depth[S]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].last){
            if(e[i].w&&depth[e[i].to]<0){
                depth[e[i].to]=depth[u]+1;
                q.push(e[i].to);
            }
        }
    }
    return depth[T]>0;
}

int dfs(int u,int flow){
    if(u==T)
        return flow;
    int x;
    for(int i=cur[u];i;i=e[i].last){
        cur[u]=i;
        if(depth[e[i].to]==depth[u]+1&&e[i].w&&(x=dfs(e[i].to,min(flow,e[i].w)))){
            e[i].w-=x;
            e[i^1].w+=x;
            return x;
        }
    }
    return 0;
}

int dinic(){
    int ans=0;
    while(bfs()){
        memcpy(cur,head,sizeof cur);
        while(int side=dfs(S,inf))
            ans+=side;
    }
    return ans;
}

void add_edge(int x,int y,int z){
    e[++cnt]=edge(y,z,head[x]);
    head[x]=cnt;
    e[++cnt]=edge(x,0,head[y]);
    head[y]=cnt;
}
