#include<iostream>
#include<algorithm>
using namespace std;


void solve()
{
    
    string s;
    string t;
    cin>>s>>t;

    int ans=-1;

    for(int i=0;i<s.size();i++)
    {
        int T=(t[i]-s[i]+26)%26;

        if(ans==-1)ans=T;
        else {
            if(T!=ans)
            {
                cout<<"No"<<endl;
                return;
            }
        }

    }

    cout<<"Yes"<<endl;

}

int main()
{
    //int t;cin>>t;while(t--)
    solve();
}