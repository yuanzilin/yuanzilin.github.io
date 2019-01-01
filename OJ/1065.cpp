#include <iostream>

using namespace std;

int n;
string s;

int main()
{
    scanf("%d",&n);
    cin>>s;
    string tmp;
    int i=0,flag=0;
    while(s[i]!='\0'){
        tmp=s.substr(i,4);
        if(tmp=="BCPC"){
            flag=1;
            cout<<"I want to join in!"<<endl;
            i+=4;
            continue;
        }
        tmp=s.substr(i,11);
        if(tmp=="ConnorZhong"){
            cout<<"I am so weak"<<endl;
            i+=11;
            continue;
        }

        tmp=s.substr(i,6);
        if(tmp=="Bamboo"){
            cout<<"this is 51's father"<<endl;
            i+=6;
            continue;
        }

        tmp=s.substr(i,10);
        if(tmp=="ModricWang"){
            cout<<"1080Ti!, wyr, silver!!!"<<endl;
            i+=10;
            continue;
        }

        tmp=s.substr(i,7);
        if(tmp=="AlvinZH"){
            cout<<"hg, shg, awsl!"<<endl;
            i+=7;
            continue;
        }
        i++;
    }
}