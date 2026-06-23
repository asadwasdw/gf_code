// #pragma GCC optimize(2)
#include<bits/stdc++.h>
// #define int 
#define endl '\n'
#define lowbits(x) ((x)&((-x)))
#define INF 0x3f3f3f3f
#define uu __int128
#define PI acos(-1)
#define ls k<<1
#define rs k<<1|1
using namespace std;
typedef  long long ll;
typedef  unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PII;
constexpr int N=2e6+10, M=2*N;
constexpr int mod=998244353;
constexpr double eps=1e-9;
int nx[] = {0, 0, 1, -1}, ny[] = {1, -1, 0, 0};


int n,m;


int a[N];

priority_queue<int> q;

void solve(){
    cin >> n >> m;
    int mx = 0;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        mx =max(mx, a[i]);
        q.push(a[i]);
    }
    if(m == 1){
        cout << mx << endl;return;
    }
    ll res = 1e18, cnt = 0;
    while(q.size()){
        int t = q.top();q.pop();
        // cout << cnt << ' ' << t << ' ' << cnt << endl;
        res = min(res, cnt + t);
        ++cnt;
        if(t / m){
            q.push(t/m);
        }
    }
    res = min(res, cnt);
    cout << res << endl;



}


signed main()
{   
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t = 1;
    // cout << fixed << setprecision(9)
    // cin >> t;
    while(t--)solve();
    return 0;

}
