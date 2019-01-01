#include <cstdio>
#include <cstring>
#include <vector>
#define MaxSize 1005
#define INF 0x3f3f3f3f
using namespace std;

int n, ans;
vector<int> G[MaxSize];//记录可攻击的敌方随从
int match[MaxSize];//记录匹配点
int visit[MaxSize];//记录是否访问

struct minion {
    int attack, life;
}A[MaxSize], B[MaxSize];

bool dfs(int x)//寻找增广路径
{
    for (int i = 0; i < G[x].size(); ++i)
    {
        int to = G[x][i];
        if(!visit[to])
        {
            visit[to] = 1;
            if(!match[to] || dfs(match[to]))
            {//这个if语句就是用来不断寻找一个未匹配点作为终点
                match[to] = x;
                //本来是从x到to的，再从to到原来的与to匹配的点(设为to0),然后再从to0到作为终点的未匹配点final_to。
                //上面这句赋值语句就是换过来，变成x与to匹配，to0与final_to匹配，这样从x到final_to原来只有仨匹配点，换过来后就变成4个匹配点了。
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()
{
    ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= n; ++i)
    {
        memset(visit, 0, sizeof(visit));//清空访问
        if(dfs(i)) ans++;//从节点i尝试扩展
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &n))
    {
        int a, l, p;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &a, &l, &p);

            switch (p) {
                case 0:
                    A[i].attack = a; A[i].life = l; break;
                case 1:
                    A[i].attack = a; A[i].life = INF; break;
                case 2:
                    A[i].attack = INF; A[i].life = l; break;
                case 3:
                    A[i].attack = INF; A[i].life = INF; break;
                default:
                    break;
            }
        }
        for (int i = 1; i <= n; ++i)
            scanf("%d %d", &B[i].attack, &B[i].life);
        for (int i = 1; i <= n; ++i)
            G[i].clear();

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(A[i].attack >= B[j].life && A[i].life > B[j].attack)
                    G[i].push_back(j);
            }
        }
        if(n == MaxMatch()) printf("YES\n");
        else printf("NO\n");
    }
}