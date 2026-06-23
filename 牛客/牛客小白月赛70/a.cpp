#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    cin>>s;

    for(auto t:s){
        if(t>='a'&&t<='z')cout<<char(t-'a'+'A');
        else cout<<char(t-'A'+'a');
    }
}