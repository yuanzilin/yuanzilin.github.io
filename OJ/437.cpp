#include <iostream>
typedef long long ll;

using namespace std;

ll n,x,t,an[10001],nplus,mode=1000007,xn[10001];

int main()
{
    int i,j,cnt=0;
    while(cin>>n>>x>>t){
        cout<<"Case #"<<++cnt<<":\n";
        xn[0]=1;
        for(i=1;i<=n;i++){
            xn[i]=(xn[i-1]*x)%mode;
        }
        while(t--){
            nplus=0;
            for(i=0;i<=n;i++){
                cin>>an[i];
                nplus=(nplus+an[i]*xn[i])%mode;
            }
            cout<<nplus<<endl;
        }
    }
}