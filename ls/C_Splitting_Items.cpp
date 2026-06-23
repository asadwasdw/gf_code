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

int a[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1,[&](int a, int b){
        return a > b;
    });



    for(int i = 2; i <= n; i += 2) {
        int w = a[i - 1] - a[i];
        w = min(w, k);
        k -= w;
        a[i] += w;
    }
    int A = 0, B = 0;
    for(int i = 1; i <= n; i ++) {
        if(i&1) A += a[i];
        else    B += a[i];
        //  cout << a[i] << " \n"[i == n];
    }

    cout << A - B << endl;
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