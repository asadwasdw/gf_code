#include<bits/stdc++.h>
#define ll long long
using namespace std;
// #define int long long
typedef pair<int,int> PII;
const int N = 3e6 + 10;
const int mod = 998244353;

int n,m;
PII a[N], temp[N];
int res[N];
void dfs(int l, int r){
    if(l >= r)return;
    if(l+1 == r){
        res[a[l].second] = 0;return;
    }
    int mid = l + r >> 1;
    dfs(l, mid);dfs(mid, r);
    int i = l, j = mid, k = l;
    while(i < mid){
        while(j < r && a[j].first < a[i].first)temp[k++] = a[j++];
        temp[k++] = a[i++];
    }
    while(j < r)temp[k++] = a[j++];
    for(k=l; k<r; ++k){
        a[k] = temp[k];
        if(r - k - 1 <= m && r - l - 1 < a[k].first)res[a[k].second]++;
    }
}

void solve() {
    cin >> n >> m;
    // cout << (1 << 20) << endl;
    for(int i=0; i<1<<n; ++i)cin >> a[i].first, a[i].second = i;
    dfs(0, 1<<n);
    for(int i=0; i<1<<n; ++i)cout << res[i] << " \n"[i == (1<<n)-1];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}