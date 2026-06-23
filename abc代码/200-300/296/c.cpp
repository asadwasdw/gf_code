#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    int n;cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        //cout<<s[i]<<endl;
        if(s[i]==s[i-1])
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;



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