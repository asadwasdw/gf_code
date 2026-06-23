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
    int n;
    cin >> n;
    string s;
    cin >> s;

    assert(n == s.size());
    assert(n <= 15);



    for(int i = 1; i <= n; i ++) {
        a[i] = s[i - 1] - '0';
        if(i >= 2 && a[i] != 1 && a[i - 1] != 1) {
            cout << "-1";
            return;
        }
    }

    ll cnt = 0;

	

    for(int i = n; i > 1; i --)  {
        cnt = (cnt + 1) * a[i];
        cnt %= mod;
    }
    cout << cnt << endl;
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