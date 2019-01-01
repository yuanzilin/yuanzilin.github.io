#include <iostream>
using namespace std;
typedef long long ll;
ll maxv=2e15,bag[5000];
int w[2000],v[2000];
int main()
{
    int n,i,j;
    ll minprice;
    while(cin>>n){
        for(i=0;i<n;i++)
            cin>>w[i]>>v[i],v[i]++;
        bag[0]=0;
        for(i=1;i<=n+2500;i++)
            bag[i]=maxv;
        for(i=0;i<n;i++){
            for(j=n+2000;j>=v[i];j--){
                bag[j]=min(bag[j],bag[j-v[i]]+w[i]);
            }
        }
        minprice=maxv;
        for(i=n;i<=n+2000;i++)
            minprice=min(minprice,bag[i]);
        cout<<minprice<<endl;
    }
}