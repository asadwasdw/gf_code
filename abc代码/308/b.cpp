#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

map<string,int>st;
string a[N];
string b[N];
void solve()
{

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    int t;
    cin>>t;
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        st[b[i]]=x;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(st[a[i]])ans+=st[a[i]];
        else ans+=t;
    }

    cout<<ans<<endl;








}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}