#include<iostream>
#include <vector>
#include <cstring>
#define maxnum 6010

using  namespace std;

bool judge_son[maxnum];
int dp[maxnum][2];
int n,l,k;
vector<int> sons[maxnum];

void dfs_build(int);

int main(){
    while (~scanf("%d",&n)){
        for(int i=0;i<=n;i++)
            sons[i].clear();
        memset(dp,0,sizeof dp);
        memset(judge_son,0,sizeof judge_son);
        for(int i=1;i<=n;i++)
            scanf("%d",&dp[i][1]);
        while(scanf("%d%d",&l,&k),l+k){
            sons[k].push_back(l);
            judge_son[l]=1;
        }
        int root=0;
        for(int i=1;i<=n;i++){
            if(!judge_son[i]){
                root=i;
                break;
            }
        }
        dfs_build(root);
        int ans=max(dp[root][0],dp[root][1]);
        printf("%d\n",ans);
    }
}

void dfs_build(int x){
    for(int i=0;i<sons[x].size();i++){
        int y=sons[x][i];
        dfs_build(y);
        dp[x][1]+=dp[y][0];
        dp[x][0]+=max(dp[y][1],dp[y][0]);
    }
}
