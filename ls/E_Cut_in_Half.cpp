#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long double,long long>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const long double eps = 1e-15;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];

void solve()
{
    int n, k, c;
    cin >> n >> k >> c;
    int mn = INF;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mn = min(a[i], mn);
    }

    // cout << mn << endl;

    vector<PII> b;
    ll m = 0;
    for(int i = 1; i <= n; i ++) {
        long double x = a[i];
        long long cnt = 1;
        while(x/2 > mn || fabs(x/2 - mn) < eps) {
            x /= 2;
            cnt *= 2;
        }
        b.push_back({x, cnt});
        m += cnt;
    }

    
    if(k < m - n) {
        priority_queue<long double> pq;
        for(int i = 1; i <= n; i ++) {
            int x = a[i];
            pq.push(x);
        }

        while(k --) {
            long double x = pq.top(); pq.pop();
            x /= 2;
            pq.push(x);
            pq.push(x);
        }

        while(c --) {
            long double x = pq.top(); pq.pop();
            if(c == 0) {
                cout << x << endl;
            }
        }
        return;
    }

    k -= m - n;


    sort(b.begin(), b.end(),[&](PII a, PII b){
        return a.first > b.first;
    });


    while(k >= m) {
        k -= m;
        m *= 2;

        for(auto&[x, cnt] : b) {
            x /= 2;
            cnt *= 2;
        }
    }
    
    for(int i = 0; i < b.size(); i ++) {
        long double x = b[i].first;
        ll cnt = b[i].second;
        if(k > cnt) {
            x /= 2;
            k -= cnt;
            cnt *= 2;
        } else {
            long double y = x / 2;
            b.push_back({y, k * 2});
            cnt -= k;
            k  = 0;
        }
        b[i] = {x, cnt};
        if(k == 0) break;
    }

    sort(b.begin(), b.end(),[&](PII a, PII b){
        return a.first > b.first;
    });

    for(auto [x, cnt] : b) {
        c -= cnt;
        if(c <= 0) {
            cout << x << endl;
            break;
        }
    }

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