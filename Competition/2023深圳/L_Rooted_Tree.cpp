#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const ll mod= 1e9 + 9;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

map<vector<int>, ll> st;
int m, k;

void dfs(vector<int> v, int kk, int p) {
    // cout << p << endl;

    if(kk == k + 1) {
        st[v] += p;
        return;
    }
    int sum = 0;
    for(int i = 2; i <= k; i ++) {
        sum += v[i - 1] - v[i] / m;
    }


    // cout << sum << endl;
    for(int i = 1; i <= k; i ++) {
        if(v[i] * m > v[i + 1] ) {
            // cout << i << endl;
            v[i + 1] += m;
            // cout <<  qmi(sum, mod - 2)  << endl;
            dfs(v, kk + 1, p * (v[i] - (v[i + 1] - m) / m) % mod * qmi(sum, mod - 2) % mod);
            v[i + 1] -= m;
        }
    }
}

void solve()
{
    st.clear();   
    // cin >> m >> k;
    vector<int> init(k + 10);
    if(k == 1) {
        cout << m << " ";
        return;
    }
    init[1] = m;
    dfs(init, 2, 1);

    ll ans = 0;
    for(auto [v, p] : st) {

        int sum = 0;
        // int cnt = 0;
        for(int i = 1; i <= k; i ++) sum += i * v[i];
        // for(int i = 1; i <= k; i ++) cout << v[i] << " \n"[i == k];
        // cout << sum << " " << p << endl;
        ans += sum * p;
        ans %= mod;
        // break;
    }
    ll tmp = 1;
    for (int i = 1; i <= k; i++) {
        ans = ans * tmp % mod;
        tmp = tmp + m - 1;
    }
    cout << ans / pow(m, 1)  << " ";

    // for(ll i = 1; i <= 100000; i ++) {
    //     for(ll j = 1; j <= 70; j ++) {
    //         if(ans == i * qmi(j, mod - 2) % mod) {
    //             // cout << __gcd(i, j) << endl;
    //             cout << i << "/" << j << " --";
    //             return;
    //         }
    //     }
    // }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    // cout << gcd({424,2718,9568,24850,83640}) << endl;
    cout << __gcd(424,2718) << endl;
    // solve();
    //cin>>t;
    for(int i = 1; i <= 6; i ++) {
        for(int j = 1; j <= 6; j ++) {
            m = i, k = j;
            solve();
        }
         cout << endl;
    }
}