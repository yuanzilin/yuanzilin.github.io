#include <iostream>
#include <cstring>

using namespace std;

int result(string,string);

int main()
{
    string str1, str2 ;
    while(cin>>str1>>str2){
        result(str1,str2)? puts("YES"):puts("NO");
    }

}

int result(string a,string b){
    int alen=a.length();
    if(alen&1){
        if(a==b)
            return 1;
        else
            return 0;
    }
    else{
        alen>>=1;
        string a1,a2,b1,b2;
        a1.assign(a,0,alen);
        a2.assign(a,alen,alen);
        b1.assign(b,0,alen);
        b2.assign(b,alen,alen);
        return result(a1,b1)&&result(a2,b2)||result(a1,b2)&&result(a2,b1);
        /*else{
            if(a1==b1&&a2!=b2)
                result(a2,b2);
            if(a1!=b1&&a2==b2)
                result(a1,b1);
            if(a1!=b1&&a2!=b2){
                if(a1==b2&&a2!=b1)
                    result(a2,b1);
                if(a1!=b2&&a2==b1)
                    result(a1,b2);
                if(a1!=b2&&a2!=b1){
                        puts("NO");

                }
            }
        }*/
    }
}