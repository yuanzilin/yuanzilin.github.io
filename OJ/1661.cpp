#include <iostream>

using namespace std;

const int maxnum=100020;
int N,ans;
int child[maxnum][2],d[maxnum];

void find_dx(int);
void find_answer(int);

int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d%d",&child[i][0],&child[i][1]);
    if(child[1][0])
        find_dx(child[1][0]);
    if(child[1][1])
        find_dx(child[1][1]);
    for(int i=1;i<=N;i++){
        find_answer(i);
    }
//    ans=d[child[1][0]]+d[child[1][1]];
    printf("%d\n",ans);
}

void find_dx(int x){
    if(child[x][0])
        find_dx(child[x][0]);
    if(child[x][1])
        find_dx(child[x][1]);
    d[x]=max(d[child[x][1]],d[child[x][0]])+1;
}

void find_answer(int x){
    int y=d[child[x][0]]+d[child[x][1]];
    ans=max(ans,y);
}