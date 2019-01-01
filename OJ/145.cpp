#include <iostream>
#include <vector>
#include <algorithm>
#define maxnum 100005

using namespace std;

int n;
struct activity{
    int s;
    int t;
    bool operator <(const activity a) const{
        return t<a.t;
    }
}acts[maxnum];

int sum()
{
    int k;
    vector<int> vec;
    sort(acts,acts+n);
    vec.push_back(0);
    k=0;
    for(int i=0;i<n;i++){
        if(acts[i].s>acts[k].t){
            vec.push_back(i);
            k=i;
        }
    }
    return vec.size();
}

int main()
{
    while (~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%d%d",&acts[i].s,&acts[i].t);
        printf("%d\n",sum());
    }
}