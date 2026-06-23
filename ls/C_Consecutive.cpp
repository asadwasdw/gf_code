#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define int long long

int a[N];
void solve()
{
    int n,m;
    cin>>n>>m;
    string s;cin>>s;s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]==s[i-1]){
            a[i]++;
        }
        a[i]+=a[i-1];
    }

    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l]<<endl;
    }
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