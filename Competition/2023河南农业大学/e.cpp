#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

unordered_map<ll,int>num;

ll a[N];

void solve()
{
    int n,m;
    cin>>n>>m;
    int cnt =0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
        num[a[i]]++;
        cnt+=num[a[i]-m];
    }
    cout<<cnt<<endl;






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