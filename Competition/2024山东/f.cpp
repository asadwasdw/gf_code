#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 2e6 + 10, mod = 1e9+7;


ll n, a[N];

void solve(){
    cin >> n;
    vector<ll> sum;
    for(int i=1; i<=n; ++i){
        cin >> a[i], a[i] += a[i-1];
        if(i != n)
        sum.push_back(a[i]);
    }
    sort(sum.begin(), sum.end());
    for(int i=1; i<n-1; ++i)sum[i] += sum[i-1];
    sum.insert(sum.begin(), 0);
    for(int i=1; i<=n; ++i){
        cout << a[n] * i - sum[i-1] << " \n"[i == n];
    }

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}