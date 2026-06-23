#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    cin>>s;

    while(s.size()!=4)
    {
        s="0"+s;
    }
    cout<<s<<endl;

}