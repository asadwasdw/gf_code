#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
const int M = 7;
set<array<int,M>>s;

void dfs(array<int,M>  t) {
    if(s.count(t)) return;
    s.insert(t);

    for(int i = 0; i < M; i ++) {
        array<int,M> T = t;
        T[i] ^= 1;
        if(i != 0) T[i - 1] ^= 1;
        if(i != M - 1) T[i + 1] ^= 1;
        dfs(T);
    }
}



void solve()
{
    // array<int,M> t;
    // for(int i = 0; i < M; i ++ ) t[i] = 0;
    // dfs(t);
    // cout << s.size() << endl;
    




    int n; cin >> n;
    if(n <= 2) {
        cout << 2 << endl;
    }
    else {
        if(n % 3 == 2) n --;
        cout << qmi(2, n) << endl; 
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}