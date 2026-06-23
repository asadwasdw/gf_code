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
int ans = 1;

void solve()
{
    int sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        sum += (ans/x) + 1;
        a[i] = (ans/x) + 1;
    }

    if(sum >= ans) {
        cout << "-1" << endl;
    }
    else {
        for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    }
}


signed main()
{


    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;

    for(int i = 1; i <= 20; i ++) {
        ans = ans*i/__gcd(ans,i);
    }
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}