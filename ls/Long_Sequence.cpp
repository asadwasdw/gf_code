#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


vector<int> v[N];
int c[N];
void solve()
{
    long long n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        int l;
        cin >> l;
        for(int j = 1; j <= l; j ++) {
            int x; cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i = 1; i <= n; i ++) cin >> c[i];

    for(int i = 1; i <= n; i ++) {
        long long t = 1ll * c[i] * v[i].size();
        // cout << i << " " << k << " " << c[i] << " " << v[i].size() <<  endl;
        if(k > t) k -= t;
        else {
            k = k % (int)v[i].size();
            if(k == 0) k = v[i].size();
            cout << v[i][k - 1];
            break;
        }
    }
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
    return 0;
}