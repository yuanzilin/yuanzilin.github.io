#include <iostream>
#include <vector>
#include <cstring>
#define maxnum 10005

using namespace std;

int n,m,k,a,b;
int match[maxnum];
bool visit[maxnum];
vector<int>  G[maxnum];

bool dfs(int);
int count();

int main()
{
    while (~scanf("%d%d%d",&n,&m,&k)){
        memset(match,0,sizeof match);
        for(int i=1;i<n;i++)
            G[i].clear();
        for(int i=0;i<k;i++){
            scanf("%d%d",&a,&b);
            if(!a||!b)
                continue;
            G[a].push_back(b);
        }
        printf("%d\n",count());
    }
}

bool dfs(int x){
    for(int i=0;i<G[x].size();i++){
        int to=G[x][i];
        if(!visit[to]){
            visit[to]=true;
            if(!match[to]||dfs(match[to])){
                match[to]=x;
                return true;
            }
        }
    }
    return false;
}

int count(){
    int ans=0;
    for(int i=1;i<n;i++){
        memset(visit,0,sizeof visit);
        if(dfs(i))
            ans++;
    }
    return ans;
}