#include<bits/stdc++.h>
#define endl '\n'
using ll = long long;
using i64 = long long;
using namespace std;
constexpr int N = 2e6 + 10;

int sum[N];
int n;
array<int, 3> a[N];
int cnt[N][3];

void clear(){
    for(int i=1; i<=n; ++i){
        for(int j=0; j<3; ++j)cnt[a[i][j]][j] = 0;
    }
    for(int i=0; i<=n+10; ++i)sum[i] = 0;
}

void solve(){
    cin >> n;
    set<int> p;
    for(int i=1; i<=n; ++i){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        for(int j=0; j<3; ++j){
            cnt[a[i][j]][j]++;
        }
    }

    for(int i = 1; i <= n; i ++) {
        int mx = max({cnt[a[i][0]][0], cnt[a[i][1]][1], cnt[a[i][2]][2]});
        sum[mx] ++;
    }

    for(int i = 1; i < n; i ++) sum[i] += sum[i - 1];
    for(int i = 0; i < n; i ++) cout << sum[i] << " \n"[i == n - 1];
    clear();
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}