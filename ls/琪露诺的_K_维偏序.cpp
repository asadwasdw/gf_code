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

int a[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    
    int j = n/2;

    for(int i = 1; i <= m; i ++) {
        int k, x;
        cin >> k >> x;

        while(a[j] < x && j <= n) j ++;
        while(j - 1 >= 1 && a[j - 1] >= x) j--;

        int id = lower_bound(a + 1, a + n + 1, x) - a;

   
        
        
        if(j > k) cout << "Yes\n";
        else cout << "No\n";
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