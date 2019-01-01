#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
struct tai{
    long long pi;
    int id;
    bool operator<(const tai t1) const{
        if(id==t1.id)
            return pi<t1.pi;
        return id<t1.id;
    }
    bool operator==(const tai &t1){
        return this->id==t1.id;
    }
};

int main()
{
    scanf("%d",&N);
    vector<struct tai> t;
    struct tai p;
    for(int i=0;i<N;i++){
        scanf("%d%lld",&p.id,&p.pi);
        t.push_back(p);
    }
//    for(int i=0;i<8;i++){
//        printf("t[%d]{"
//               "int id=%d; "
//               "lonng long pi=%lld;"
//               "}\n",i,t[i].id,t[i].pi);
//    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
//    for(int i=0;i<t.size();i++){
//        printf("t[%d]{"
//               "int id=%d; "
//               "lonng long pi=%lld;"
//               "}\n",i,t[i].id,t[i].pi);
//    }
    long long sum=0,tmp=t[0].pi;
    int dic=0;
    //cout<<t.size()<<endl;
    for(int i=0;i<t.size()-1;i++){
        dic=t[i+1].id-t[i].id;
        sum+=dic*tmp;
        if(t[i+1].pi<tmp)
            tmp=t[i+1].pi;
    }
    printf("%lld\n",sum);
}