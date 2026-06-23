#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ull INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);
ull a[N];
void solve()
{
    int n;
    cin >> n;

    ull ans = 0;

    stack<ull>s;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        while(s.size() && a[i] >= a[s.top()]) {
            ull r = s.top(); s.pop();
            ans ^=  r;
        }
        ans ^=  i;
        s.push(i);
        cout << ans << endl;
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