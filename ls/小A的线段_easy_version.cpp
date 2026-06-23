#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int l[N],r[N];
int ST[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < m; i ++) {
        cin >> l[i] >> r[i];
    }

    for(int st = 1; st < (1<<m); st ++) {
        if(ST[st]) {
            ans++;
        }
        else {
            vector<int>a(n+10);
            for(int j = 0; j < m; j ++) {
                if((st >> j) & 1) {
                    a[l[j]]++,a[r[j] + 1]--;
                }
            }
            int i = 1;
            for(; i <= n; i ++) {
                a[i] += a[i - 1];
                if(a[i] < 2) break;
            }
            if(i == n + 1) {
                ST[st] = true;
                ans++;
            }
        }

        if(ST[st]) {
            for(int j = 0; j < m; j ++) {
                ST[st|(1<<j)] = true;
            }
        }
    }

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
}