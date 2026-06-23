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


void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> s(n + 1, 0);
    vector<int> b(n + 1, 0); // b数组的前n个元素,
    vector<int> s2(n + 1, 0); // c矩阵中每一行的和
    vector<int> s22(n + 1, 0);// s2的前缀和，用于快速计算c矩阵前i行的的和
    vector<int> d(n + 1, 0); // c矩阵的每一行有效元素数量的前缀和，用来确定当前数在多少行

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
        b[i] = b[i - 1] + s[i];
        d[i] = n - i + 1 + d[i - 1];
    }

    s22[1] = s2[1] = b[n];
    for(int i = 2; i <= n; i ++) {
        s2[i] = s2[i - 1] - (n - i + 2) * a[i - 1];
        s22[i] = s2[i] + s22[i - 1];
    }

    auto get = [&](int l, int r) -> int { // 计算c矩阵中，从(l,l)到(l, l + r - 1)的和
        return b[r] - b[l - 1] - (s[l - 1]) * (r - l + 1);
    };

    auto calc = [&](int x) -> int {
        int i = lower_bound(d.begin() + 1, d.end(), x) - d.begin();
        int res = s22[i - 1];
        x -= d[i - 1];
        res += get(i, i + x - 1);
        return res;
    };


    int q; cin >> q;
    while(q --) {
        int x, y; cin >> x >> y;
        cout << calc(y) - calc(x - 1) << endl;
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
}