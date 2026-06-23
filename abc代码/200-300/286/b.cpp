
#include<iostream>
#include<algorithm>

using namespace std;

string s;
string ans;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    ans+=s[1];
    for(int i=2;i<=n;i++)
    {
        if(s[i]=='a'&&s[i-1]=='n')
        {
            ans+='y';
        }
        ans+=s[i];
    }

    cout<<ans<<endl;
}