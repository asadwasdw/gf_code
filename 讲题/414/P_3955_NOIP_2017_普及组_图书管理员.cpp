#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];


void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    
    while(m --) {

        string s,t;
        int len, x; cin >> len >> s;
        int i = 1;
        for(; i <= n; i ++) {
            t = to_string(a[i]);
            if(s == t.substr(max(0, (int)t.size() - len) ,len)) {
                cout << t << " \n";
                break;
            }
        }
        if(i == n + 1) cout << "-1\n";
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