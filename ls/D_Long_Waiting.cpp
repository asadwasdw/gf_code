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

int a[N], b[N], c[N];
int ans[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    queue<array<int,4>> q;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    int now = 0;
    int nowt = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i] >> c[i];
        q.push({a[i], b[i], c[i], i});

        while(pq.size() && now + c[i] > k) {
            now -= pq.top().second;
            nowt = max(nowt, pq.top().first);
            pq.pop();
        }

        nowt = max(a[i], nowt);
        pq.push({nowt + b[i], c[i]});
        now += c[i];
        cout << nowt << endl;
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