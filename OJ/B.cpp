#include <iostream>

using namespace std;

int goat(int n);

int main()
{
    int n;
    while(cin>>n)
        cout<<goat(n)<<endl;
}

int goat(int n){
    if(n<=4) return 1;
    else
        return goat(n-1)+goat(n-4);
}