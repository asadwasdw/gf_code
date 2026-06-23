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
ll d[N], s[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i ++) {
        cin >> d[i];
        s[i] = s[i - 1] + d[i];
        // cout << s[i] << " \n"[i == m];
    }
    s[m + 1] = INF;
    for(int i = 1; i <= n; i ++) {
        int j = 0;
        int ans = 0;
        bool ky = false;
        while(j < m) {
            int l = j;
            j = lower_bound(s + 1, s + m + 2, abs(a[i]) + s[l]) - s;
            if(j == m + 1) j --;
            // cout << a[i] << " " << j << endl;
            if(a[i] < 0) a[i] += s[j] - s[l];
            else a[i] -= s[j] - s[l];
            if(a[i] == 0) {
                ky = true;
                break;
            }
            
        }

        if(ky) cout << "Yes " << j << endl;
        else cout << "No " << a[i] << endl;
    }

}

void solve2() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i ++) {
        cin >> d[i];
        s[i] = s[i - 1] + d[i];
        // cout << s[i] << " \n"[i == m];
    }
    s[m + 1] = INF;
    for(int i = 1; i <= n; i ++) {
        bool ky = false;
        int j = 1;
        for(; j <= m; j ++) {
            if(a[i] > 0) a[i] -= d[j];
            else a[i] += d[j];
            if(a[i] == 0) {
                ky = true;
                break;
            }
        }
        if(ky) cout << "Yes " << j << endl;
        else cout << "No " << a[i] << endl;
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