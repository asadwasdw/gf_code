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
int tt[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


bool check(string t) {
    int m = (t[0] - '0') * 10 + (t[1] - '0');
    int d = (t[3] - '0') * 10 + (t[4] - '0');
    // cout << t << " " << m << " " << d << endl;
    if(0 <= m && m <= 12 && 0 <= d && d <= tt[m]) return true;
    return false;
}

int ans = INF;

void dfs(string s, int i, int cnt) {

    if(check(s)) {
        ans = min(ans, cnt);
        return;
    }

    if(i >= s.size()) {
        return;
    }
    if(i==2)dfs(s,i + 1, cnt);

    for(char t = '0'; t <= '9'; t ++) {
        string st = s;
        int w = 1;
        if(st[i] == t) w = 0;
        st[i] = t;
        dfs(st, i + 1, cnt + w);
    }

}


void solve()
{
    string s;
    cin >> s;
    dfs(s, 0, 0);
    cout << ans << endl;

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
    return 0;
}