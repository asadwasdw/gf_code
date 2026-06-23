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
vector<int> lsh;

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        lsh.push_back(x);
    }
    lsh.push_back(-INF);
    lsh.push_back(+INF);

    sort(lsh.begin(), lsh.end());

    auto check = [&](int x, int mid) -> int {
        return upper_bound(lsh.begin(), lsh.end(), x + mid) - lower_bound(lsh.begin(), lsh.end(), x - mid);
    };

    for(int i = 1; i <= m; i ++) {
        int x, k;
        cin >> x >> k;
        int l = 0, r = INF/2;

        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(x, mid) >= k) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
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