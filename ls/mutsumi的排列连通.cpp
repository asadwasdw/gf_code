#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n;cin>>n;
    vector<int>a(n+1),b(n+1);
    unordered_map<int,int>st;

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=x;
        st[x]=i;
    }
    int ans = n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        b[i]=x;
        if( (i==1||i==n) && (a[i]==b[i]))
        {
           
        }
        else  ans=min(ans,max(1,abs(i-st[x])));
        // cout<<i<<" "<<ans<<endl; 
    }
    cout<<ans<<endl;
    if(ans!=n && n!=1)cout<<min(2,ans)<<endl;
    else cout<<"-1"<<endl;

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