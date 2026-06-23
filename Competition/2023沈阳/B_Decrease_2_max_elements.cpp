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
    int n; cin >> n;
    priority_queue<int> q; 
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        q.push(a[i]);
    }
    int cnt = 0;

    while(1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        if(b <= 0) break;
        a --, b --;
        q.push(a);
        q.push(b);
        cnt ++;
    }
    cout << cnt;








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