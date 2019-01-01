#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 4000

using namespace std;

int i,j,n,m;
int a[maxn],b[maxn];
priority_queue <int,vector<int>,greater<int> > que;

void clear(priority_queue <int,vector<int>,greater<int> > &q){
    priority_queue <int,vector<int>,greater<int> > empty;
    swap(empty,q);
}

int main()
{
    while(cin>>n>>m){
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            cin>>b[i];
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                que.push(a[i]+b[j]);
            }
        while((m--)>1)
            que.pop();
        cout<<que.top()<<endl;
        clear(que);
    }
}