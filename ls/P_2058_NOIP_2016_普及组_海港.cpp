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

typedef pair<int,vector<int>> PIV;

void solve()
{
    queue<PIV> q;

    int n;
    cin >> n; 
    map<int,int> cnt;
    int ans = 0;
    for(int i = 1; i <= n; i ++)  {
        int time, m;
        cin >> time >> m;
        vector<int> t;
        for(int j = 1; j <= m; j ++) {
            int x; cin >> x;
            t.push_back(x);
            cnt[x] ++;
            if(cnt[x] == 1) ans ++;
        }

        q.push({time, t});

        while(q.size() && q.front().first <= time - 86400) {
            auto [t, v] = q.front(); q.pop();
            for(auto x : v) {
                cnt[x] --;
                if(cnt[x] == 0) ans --;
            }
        }

        // cout << time << endl;

        // for(int i = 1; i <= 4; i ++) cout << cnt[i] << " \n"[i == n];

        cout << ans << endl;



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
    return 0;
}