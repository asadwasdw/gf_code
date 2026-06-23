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
#define x first
#define y second
using db = long double;

//vector<vector<int>>adj(N);
const db eps = 1e-8;

void solve()
{
    int n, m, L, V;
    cin >> n >> m >> L >> V;
    vector<int> a(N + 10, 0);
    vector<int> b;
    vector<PII> v, line;

    for(int i = 1; i <= n; i ++) {
        db l, r;
        db d, v, a;
        cin >> d >> v >> a;
        if(a == 0) {
            if(v <= V) continue;
            l = d, r = L;
        }
        else if(a < 0) {
            if(v <= V) continue;
            a = fabs(a);
            db lmt = (V - v) / a;
            db lms = v * lmt + 0.5 * a * lmt * lmt;
            cerr << 
            l = d, r = d + (lms) - eps;
            r = min(L, (int)r);

        } else {
			if(v > V) l = d, r = L;
			else {
				double lt = V - v;
				double t = lt / a;
				double sum = v * t + 0.5 * a * t * t;
				l = d + sum + eps + 1 , r = L;
                // cout << l << " " << r << endl;
                
                if((int)l > L) continue;
			}
        }
        cerr << i << " " << l << " " << r << endl;
        line.push_back({l, r});
    }

    for(int i = 1; i <= m; i ++) {
        int x; cin >> x; a[x] ++;
        b.push_back(x);
    }
    for(int i = 1; i <= L; i ++) {
        a[i] += a[i - 1];
    }

    for(auto [l, r] : line) {
        if(l == 0) {
            l = 1;
            if(a[0]) {
                v.push_back({0, r});
                continue;
            }
        }
        if(a[r] - a[l - 1]) v.push_back({l, r});
    }

    cout << v.size() << " ";
    if(v.size() == 0) {
        cout << m << endl;
        return;
    }

    sort(v.begin(), v.end(),[&](PII a, PII b){
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });

    // for(auto [l, r] : v) cout << l << " " << r << endl;


    int id = upper_bound(b.begin(), b.end(), v[0].y) - b.begin() - 1;
    int res = 1;
    int pos = b[id];
    for(int i = 1; i < v.size(); i ++) {
        if(v[i].x <= pos && pos <= v[i].y) continue;
        id =  upper_bound(b.begin(), b.end(), v[i].y) - b.begin() - 1;
        pos = b[id];
        ++res;
    }
    cout << m - res  << endl;
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