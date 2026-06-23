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

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a[x] = 1;
    }

    int x = 0, m = INF;

    auto calc = [&](int start) {
        int len = 0, pos = 101;
        for (int i = start; i >= 1; i -= 2) {
            if (a[i] == 0) {
                pos = i; 
                ++len;
            } else {
                if (len > x) {
                    x = len;
                    m = pos;
                } else if(len == x) {
                    m = min(pos, m);
                }
                len = 0;
            }
        }
    
        if (len > x) {
            x = len;
            m = pos;
        } else if(len == x) {
            m = min(pos, m);
        }
    };

    calc(100);
    calc(99);
    cout << m << " " << x << endl;
}


void solve2() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a[x] = 1;
        assert(1 <= x && x <= 100);
    }

    int x = -1, m = INF;

    for(int l = 1; l <= 100; l ++) {
        for(int len = 0; l + len * 2 - 2 <= 100; len ++) {
            int r = l + len * 2 - 2;
            int res = 0;
            for(int i = l; i <= r; i += 2) {
                res += a[i];
            }
            // if(res == 0)cout << l << " " << len << " " << endl;

            if(res == 0) {
                if (len > x) {
                    x = len;
                    m = l;
                } else if(len == x) {
                    m = min(l, m);
                }
            } 
        }
    }

    cout << m << " " << x << endl;
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