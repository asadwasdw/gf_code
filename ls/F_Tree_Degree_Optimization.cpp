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


void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int ans = 0;
    priority_queue<PII,vector<PII>,greater<PII> >q; 
    for(int i = 1; i <= n; i ++) {
        ans += a[i];
        q.push({a[i] * 3, 2});
    } 

    for(int i = 1; i <= n - 2; i ++) {
        auto [w, num] = q.top();
        ans += w;
        q.pop();
        w /= num*num - (num - 1) * (num - 1);
        num ++;
        q.push({(num*num - (num - 1) * (num - 1)) * w, num});
    }


    cout << ans ;

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