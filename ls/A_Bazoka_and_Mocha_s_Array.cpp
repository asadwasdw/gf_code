#include<bits/stdc++.h>
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


void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    int num = 0;

    for(int i = 2; i <= 2 * n; i ++) {
        if(a[i] >= a[i - 1]) num ++ ;
        else num = 0;
        // cout << i << " " << num << endl;
        if(num == n - 1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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