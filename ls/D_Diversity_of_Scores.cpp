#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
unordered_map<ll,int>num;
int a[N];
void solve()
{
    int n,q;
    cin>>n>>q;
    int ans = 1;
    num[0] = n;
    for(int i=1;i<=q;i++) {
        int x,y;
        cin>>x>>y;
        if(--num[a[x]] == 0) ans--;
        a[x]+=y;
        if(  num[a[x]]++ == 0) ans ++;
        cout<<ans<<endl;
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