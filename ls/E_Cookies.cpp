#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


typedef long long ll;
void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n + 10);
    vector<ll> d(n + 10);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.begin() + n + 1,[&](int x, int y){
        return x > y;
    });

    ll mx = a[1] * k;
    cout << mx << endl;
    x--;
    for(int i = 2; i <= n; i ++) {
        d[i] = a[1] - a[i]; // 改为损失值
        
    }

    priority_queue<array<ll,3>, vector<array<ll,3>>, greater<array<ll,3>>> q; 
    //{三个参数cur, id, cnt} 分别代码当前的损失值， 上一个被替换的编号， 已经替换的个数
    
    q.push({d[2], 2, 1}); // 最小损失就是用一个a_2，所以直接用这个状态做起点开搜

    while(x && q.size()) {
        auto[cur, id, cnt] = q.top(); q.pop();

        cout << mx - cur << endl;
        x --;

        if(id + 1 <= n) {
            q.push({cur - d[id] + d[id + 1], id + 1,cnt});
        }

        if(cnt < k) {
            q.push({cur + d[id], id, cnt + 1});
        }
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