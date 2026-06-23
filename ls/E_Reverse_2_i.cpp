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

int a[N];

void dfs(int l, int r) {
    if(l >= r) return;
    // cerr << l << " " << r << endl;
    int mid = l + r >> 1;
    int mnl = INF, mnr = INF;
    for(int i = l; i <= r; i ++) {
        if(i <= mid) mnl = min(a[i], mnl);
        else mnr = min(a[i], mnr);
    }
    if(mnr < mnl) {
        for(int i = l, j = mid + 1; j <= r; i ++, j ++) swap(a[i], a[j]);
        
    }
    dfs(l, mid);
    dfs(mid + 1, r);
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= (1 << n); i ++) {
        cin >> a[i];
    }

    dfs(1, 1 << n);
    

    for(int i = 1; i <= (1 << n); i ++) cout << a[i] << " "; cout << endl;



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