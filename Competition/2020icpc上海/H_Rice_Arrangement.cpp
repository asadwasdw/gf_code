#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

ll a[N],b[N],c[N];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    
    sort(a,a+m);
    sort(b,b+m);

    ll ans = INF;
    
    for(int i = 0;i < m; i++ ){// 枚举第一个人吃哪个?
        for(int j = 0; j < m ; j++) c[j] = (b[(j+i) % m] - a[j] + n) % n;// 枚举每个人顺时针需要转多少
            sort(c, c + m);
            // for(int j = 0; j < m; j++) cout << b[j] <<" "; cout << endl;
            ans = min({ans, n - c[0], c[m-1]});
            c[m] = 0; // 多组案例,可能没有清空覆盖到c[m]
            for(int j = 0;j < m ; j++) {
                ans = min(ans,c[j] + c[j] + n - c[j + 1]); // 先转好前j个
                ans = min(ans, (n - c[j + 1]) * 2 + c[j]); // 先转好后面的
            }
    }

    cout << ans << endl;





}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}