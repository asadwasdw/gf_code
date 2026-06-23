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

int a[] = {6,2,5,5,4,5,6,3,7,6};

string dp[N];


bool check(string& a, string& b) {
    if(b == "-1") return true;
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i = 0; i < a.size(); i ++) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

void solve()
{
    
    for(int i = 0; i <= 1e3 + 1; i ++) {
        dp[i] = "-1";
        for(int j = 0; j <= 9; j ++) {
            if(a[j] > i) continue;
            string w = dp[i - a[j]];
            if(w == "-1") w = "";
            if(w == "" && (j == 0 || i != a[j])) continue;

            w += (char)('0' + j);
            if(check(w, dp[i])) {
                dp[i] = w;
            }
        }
    }

    for(int i = 1; i <= 200; i ++) {
        cout << i << " " << dp[i] << endl;
    }

    int n; cin >> n;
    while(n --) {
        int x; cin >> x;
        if(x >= 1e3) {
            int cnt = (x - 1e3 + 6) / 7;
            cout << dp[x - 7 * cnt];
            while(cnt --) cout << "8";
        } else cout << dp[x];

        cout << endl;
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