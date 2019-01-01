#include <iostream>
#include <cstring>
#include <queue>
#define maxn 1005
#define maxedge 200010
#define inf 999

using namespace std;

int cnt=1;
int n,m,a,b,c;
int S,T;
int depth[maxn],head[maxn],cur[maxn];
struct edge{
    int to,w,last;
    edge(){}
    edge(int x,int y,int z){
        to=x,w=y,last=z;
    }
}e[maxedge];

bool bfs();
int dfs();
int dinic();
void add_edge(int,int,int);

int main()
{
    scanf("%d%d",&n,&m);
    S=1,T=n;
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        add_edge(a,b,c);
    }
    printf("%d\n",dinic());
}

bool bfs()
{
    queue<int> q;
    q.push(S);
    memset(depth,-1,sizeof depth);
    depth[S]=0;
    while (!q.empty()){
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

int dinic()
{
    int ans=0;
    while(bfs()){
        memcpy(cur,head,sizeof cur);
        while(int side=dfs(S,inf))
            ans+=side;
    }
    return ans;
}

void add_edge(int x,int y,int z)
{
    e[++cnt]=edge(y,z,head[x]);
    head[x]=cnt;
    e[++cnt]=edge(x,z,head[y]);//如果是有向图，就该把这行代码的z替换成0
    head[y]=cnt;
}
