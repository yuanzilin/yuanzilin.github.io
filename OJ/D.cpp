#include <iostream>
#include <cstring>
#define mode 1000000007

using namespace std;

int n,i,len;
long long y;
char input[1000001];

int main()
{
    cin>>n;
    while(n--){
        scanf("%s",input);
        y=input[0]-'0';
        for(i=0;input[i]!='\0';i++);
        len=i;
        for(i=1;i<len;i++){
            y=(input[i]-'0'+(8*y))%mode;
        }
        cout<<y<<endl;
    }
}