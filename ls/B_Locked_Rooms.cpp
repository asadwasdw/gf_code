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

void solve()
{
    int n; 
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int ans = n + 1;
    set<int> s; s.insert(0); s.insert(n);
    for(int i = 1; i <= n; i ++) {
        if(a[i]) break;
        s.insert(i);
    }

    for(int i = n; i >= 1; i --) {
        if(a[i]) break;
        s.insert(i - 1);
    }

    cout << n + 1 - s.size() << endl;

  









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