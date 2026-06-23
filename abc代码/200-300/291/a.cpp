#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            cout<<i+1;
            return ;
        }
    }
}

int main()
{
   // int t;cin>>t;while(t--)
    solve();
}