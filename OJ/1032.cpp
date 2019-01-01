#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define maxnum 100005
typedef long long ll;

using namespace std;

int n;
struct classes{
    int last,end;
    bool operator <(const classes& tmp){
        return this->end==tmp.end?this->last<tmp.last:this->end<tmp.end;
    }
}c[maxnum];

int main()
{
    while (~scanf("%d",&n))
    {
        int cnt=0,sgn=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&c[i].last,&c[i].end);
        }

        sort(c+1,c+n+1);
        priority_queue<int> q;//这个优先队列是用来存上了哪些课程的
        for(int i=1;i<=n;i++){
            sgn+=c[i].last;//先不管那么多，先把这个课程加进去
            q.push(c[i].last);
            if(c[i].end<sgn){//如果把这个课程加进去以后超出了当前课程的DDL，那么就减掉已加入课程里面用时最长的，即优先队列队头
                sgn-=q.top();
                q.pop();//把耗时最长的课程从队列里删除
            }
        }
        printf("%d\n",q.size());
    }
}