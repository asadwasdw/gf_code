#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


int tr[N];
int n;
void add(int k, int x) {
    for(int i = k; i <= n; i += i & -i) 
        tr[i] += x;
}

ll ask(int k) {
    ll res = 0;
    for(int i = k; i > 0; i -= i & -i) res += tr[i];
    return res;
}

ll query(int l, int r) {
    if(l > r) return 0;
    return ask(r) - ask(l - 1);
}

void solve()
{
    cin >> n;
    map<int,int> id;
    for(int i = 1; i <= n ; i ++) tr[i] = 0;
    for(int i = 1; i <= n; i ++) add(i, 1); 
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        id[x] = i;
    }

    int ans = 0;


    for(int i = 1; i <= n; i ++) {
        int j = id[i];
        int l = query(1, j - 1);
        int r = query(j + 1, n);

        ans += min(l, r);
        add(j, -1);
    }
    cout << ans << endl;



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