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

//vector<vector<int>>adj(N);


bool cmp(int a, int b) {
    return a > b;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector a(n + 10, vector<int>(m + 10, 0));

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x = i + k, y = j + k;
            if(x > n + 1 || y > m + 1) continue;
            a[i][j] ++;
            a[i][y] --;
            a[x][j] --;
            a[x][y] ++;
        }
    }

    
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j ++) cout << a[i][j] << " \n"[j == m];
    // }

    vector<int> w;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            a[i][j] += - a[i - 1][j - 1] + a[i - 1][j] + a[i][j - 1]; 
            w.push_back(a[i][j]);
        }
    }

    sort(w.begin(),w.end(),cmp);
    int num; cin >> num;
    vector<int> w2;
    while(num--) {
        int x; cin >> x;
        w2.push_back(x);
    }
    sort(w2.begin(),w2.end(),cmp);

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= m; j ++) cout << a[i][j] << " \n"[j == m];
    // }

    int ans = 0;
    for(int i = 0; i < w.size() && i < w2.size(); i ++) {
        ans += w[i] * w2[i];
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
}