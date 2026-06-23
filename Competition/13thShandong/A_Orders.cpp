#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    int n,k;cin>>n>>k;
    //cout<<n<<k<<endl;
    vector<PII>jf(n+10,{0,0});

    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        jf.push_back({a,b});
    }
    sort(jf.begin(),jf.end());
    int sum = 0;
    for(auto t:jf)
    {
        sum+=t.second;
        if(sum>t.first*k){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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