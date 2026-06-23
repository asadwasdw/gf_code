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
unordered_map<int,bool>st;

int a[N];

void solve()
{
    int n,k;
    cin>>n>>k;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(st[x])continue;
        st[x] =true;
        if(x>k)continue;
        else ans +=x;
    }
    cout << (1+k)*k/2 - ans <<endl;







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}