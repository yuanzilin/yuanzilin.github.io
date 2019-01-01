#include <iostream>
#include <cstring>
#include <queue>
#define maxn 1005
#define maxedge 3000
#define inf 0xffffff

using namespace std;

int cnt=1,id,sum;
int n,m;
int S,T;
int s[35][35];
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
    memset(head,-1, sizeof(head));
    scanf("%d%d",&m,&n);
    S=0,T=n*m+1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&s[i][j]);
            sum+=s[i][j];
            id++;
            if((i+j)%2){
                add_edge(S,id,s[i][j]);
                if(j<n) add_edge(id,id+1,inf);
                if(j>1) add_edge(id,id-1,inf);
                if(i<m) add_edge(id,id+n,inf);
                if(i>1) add_edge(id,id-n,inf);
            }
            else
                add_edge(id,T,s[i][j]);
        }
    printf("%d\n",sum-dinic());
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
//        memcpy(cur,head, sizeof(cur));
        for(int i=0;i<=T;i++)
            cur[i]=head[i];//或者用上面那行注释掉的代码也行
        while(int side=dfs(S,inf))
            ans+=side;
    }
    return ans;
}

void add_edge(int x,int y,int z)
{
    e[++cnt]=edge(y,z,head[x]);
    head[x]=cnt;
    e[++cnt]=edge(x,0,head[y]);
    head[y]=cnt;
}
