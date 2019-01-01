#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define maxnum 105

using namespace std;

int n,m;
int flag=0;
int match[maxnum];
bool visit[maxnum];
vector <int> G[maxnum];

bool dfs(int);
void count();

int main()
{
    int a=0,b=0;
    scanf("%d%d",&m,&n);
    memset(match,0,sizeof match);
    for(int i=0;i<=m;i++)
        G[i].clear();
    while(scanf("%d%d",&a,&b)==2&&a!=-1&&b!=-1){
        G[a].push_back(b);
    }
    count();
    if(flag){
        for(int i=m+1;i<=n;i++){
            if(match[i])
                printf("%d %d\n",match[i],i);
        }
    }
}

bool dfs(int x){
    for(int i=0;i<G[x].size();i++){
        int to=G[x][i];
        if(!visit[to]){
            visit[to]=true;
            if(!match[to]||dfs(match[to])){
                /*这个条件语句及其内容是用于把增广路径中的匹配边改成非匹配边，非匹配边改成匹配边：
                 * 本来是从x到to的，再从to到原来的与to匹配的点(设为to0,即dfs(match[to])),然后再从to0到作为终点的未匹配点final_to(此时match[final_to]==0)。上面这句赋值语句就是换过来，变成x与to匹配，to0与final_to匹配，这样从x到final_to原来只有仨匹配点，换过来后就变成4个匹配点了。*/
                match[to]=x;
                return true;
            }
        }
    }
    return false;
}

void count(){
    int ans=0;
    for(int i=1;i<=m;i++){
        memset(visit,0,sizeof visit);//重新寻找增广路径时需把visit数组置0
        if(dfs(i))
            ans++;
    }
    if(ans){
        flag=1;
        printf("%d\n",ans);
    }
    else
        printf("No Solution!\n");
}