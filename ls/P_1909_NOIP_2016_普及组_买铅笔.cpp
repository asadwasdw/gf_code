#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int A[] = {0, 1, 2, 3};

void solve()
{
    int n, a, b, c, d, e, f;
    cin >> n >> a >> b >> c >> d >> e >> f;

    // 总价 = 单价(b) * 数量

    int sum1 = ((n + a - 1) / a) * b;
    int sum2 = ((n + c - 1) / c) * d;
    int sum3 = ((n + e - 1) / e) * f;


    // cout << min(min(sum1, sum2), sum3);
    // cout << min({sum1, sum2, sum3});

    if(sum1 <= sum2 && sum1 <= sum3) {
        cout << sum1;
    } else if(sum2 <= sum3 && sum2 <= sum1) {
        cout << sum2;
    } else {
        cout << sum3;
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