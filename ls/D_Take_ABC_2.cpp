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

bool f[N];

void solve()
{
    string a;
    cin >> a;

    int i = 0, j = 1, k = 2;
    int ans = 0;

    while(k < a.size()) {
        while( i < a.size() && a[i] != 'A') i ++;
        j = max(j, i + 1);
        while( j < a.size() && a[j] != 'B') j ++;
         k = max(k, j + 1);
        while( k < a.size() && a[k] != 'C') k ++;

        if(i < j && j < k && k < a.size() && a[i] == 'A' && a[j] == 'B' && a[k] == 'C') {
            i ++;
            j ++;
            k ++;
            ans ++;
            // cout << i << " " << j << " " << k << endl;
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
    return 0;
}