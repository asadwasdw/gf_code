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




void solve()
{
    multiset<int> s;
    queue<int> q;
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    // cout << n << " " << k << " " << p << " " << m << endl;
    vector<int> a(n + 1, 0);
    int ans = 0;
    int P = p;
    auto cp = [&](int x) {
        // cout << x << " ";
        s.erase(s.find(x));
        m -= x;
        q.push(x);
        s.insert(q.front());
        q.pop();
        P --;
    };

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(i <= k) {
            s.insert(a[i]);
        } else {
            q.push(a[i]);
        }
    }

    while(m >= *s.begin()) {
        // cout << ans << " " << m << " " << a[p] << endl;
        if(P <= k && m >= a[p]) {
            cp(a[p]);
            ans ++;
            P = n;
            
        } else if(m >= *s.begin()) {
            cp(*s.begin());
            // cout << P << endl;
        }
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
    return 0;
}