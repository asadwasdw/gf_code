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


void solve()
{
    int n;
    cin >> n;
    vector a(n + 1, 0);
    
    int l = n + 1, r = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++) {
        if(n - i + 1 != a[i]) {
            l = i;
            break;
        }
    }


    for(int i = l + 1; i <= n; i ++) {
        if(a[i] == n - l + 1) {
            r = i;
            break;
        }
    }

    // cout << l << " " << r << endl;

    for(int i = l, j = r; i < j; i ++, j --) {
        swap(a[i], a[j]);
    }

    for(int i = 1; i <= n; i ++) {
        cout << a[i] << " \n"[i == n];
    }







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
    return 0;
}