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
int b[N];


void solve()
{
    cin >> n;
    stack<PII>s;
    s.push({INF,0});
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        while(s.size() && a[i] > s.top().first) s.pop();
        b[i] = b[s.top().second] + (i - s.top().second) * a[i]; 
        cout << b[i] + 1<< " ";
        s.push({a[i],i});
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