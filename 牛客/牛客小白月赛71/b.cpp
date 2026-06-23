#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{

    string s;
    cin>>s;

    bool ky = false;

    for(int i=2;i<s.size();i++)
    {
        if(s[i]=='e'&&s[i-1]=='v'&&s[i-2]=='o')ky=true;
        if(s[i]=='e'&&s[i-1]=='v'&&s[i-2]=='l')ky=true;
        if(s[i]=='e'&&s[i-1]=='o'&&s[i-2]=='l')ky=true;
        if(s[i]=='v'&&s[i-1]=='o'&&s[i-2]=='l')ky=true;
    
    }
    if(ky)cout<<"YES";
    else cout<<"NO";


}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}