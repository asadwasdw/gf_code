#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;






void solve()
{
    string s;
    string ans;
    deque<int>a;

    cin>>s;
    int n=s.size();
    s=" "+s;

    for(int i=1;i<=n;i++)
    {
        if(a.size()==0||s[i]>s[a.front()])
        {
           ans=ans+s[i];
            a.push_back(i);
        }
        else 
        {
        ans=s[i]+ans;
            a.push_front(i);
        }
    }

  cout<<ans<<endl;

    // for(auto t:a)
    // {
    //     cout<<s[t];
    // }
    // cout<<endl;









}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}