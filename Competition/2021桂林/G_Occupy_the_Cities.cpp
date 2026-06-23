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

//vector<vector<int>>edg(N);
int n,m;
int a[N];
bool st[N];

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    n = s.size();
    s = " " + s;
    auto check = [&](int x) -> bool {
        int l = 0;
        for(int i = 1; i <= n; i ++) {
            if(s[i] == '1') {
                int r = i;

                if(l < i - x - 1) return false;
                while(r + 1 <= n && s[r + 1] == '1') r ++;
                
                if(i == r) {
                    if(l == i - x - 1) l = max(l, i + x - 1);
                    else l = max(l, i + x);
                }
                else {
                    l = max(l,r + x);
                }
                i = r;
            }
        }
        // cout << x << " " << l << endl;
        return l >= n;
    };

    int l = 0, r = n  + 10;
    while (l < r) {
        int m = l + r >> 1;
        if (check(m)) r = m;
        else l = m + 1;
    }
    cout << l << '\n';
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