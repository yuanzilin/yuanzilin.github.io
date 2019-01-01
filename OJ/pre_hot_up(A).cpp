#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 700

using namespace std;

int n,temb;
int a[maxn][maxn],minnum[maxn];
struct item{
    int s,b;
    item(int s,int b):s(s),b(b){}
    bool operator <(const item&du) const{
        return s>du.s;
    }
};

void output();
void merge(int [],int [],int [],int);

int main()
{
    int i,j;
    while(cin>>n){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>a[i][j];
        for(i=0;i<n;i++)
            sort(a[i],a[i]+n);
        output();
    }
}

void merge(int a[],int b[],int c[],int n)
{
    int i;
    priority_queue<item> que;
    for(i=0;i<n;i++)
        que.push(item(a[i]+b[0],0));
    for(i=0;i<n;i++){
        item haha=que.top();
        c[i]=haha.s;
        temb=haha.b;
        que.pop();
        if(temb+1<n)
            que.push(item(haha.s-b[temb]+b[temb+1],temb+1));
    }
}
void output()
{
    int i;
    for(i=0;i<n;i++){
        sort(a[i],a[i]+n);
        minnum[i]=a[0][i];
    }

    for(i=1;i<n;i++)
        merge(minnum,a[i],minnum,n);

    for(i=0;i<n;i++)
        cout<<minnum[i]<<" ";
    cout<<endl;
}