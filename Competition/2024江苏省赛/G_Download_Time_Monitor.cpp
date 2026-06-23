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
int B;
PII a,b;



void solve()
{
    cin >> B >> a.first >> a.second >> b.first >> b.second;
    bool f = false;
    if(a.first > b.first)swap(a, b), f= true;
    double res1 = 0, res2 = 0;
    if((b.first - a.first) * B >= a.second)res1 += 1.*a.second / B, a.second = 0;
    else res1 += b.first - a.first, a.second -= (b.first - a.first) * B;
    int t = min(b.second, a.second);
    a.second -= t;b.second -= t;
    res1 += 1.*t / (B / 2.0);res2 += 1.*t / (B / 2.0);
    res1 += 1.*a.second / B;res2 += 1.*b.second / B;
    if(f)cout << res2 << ' ' << res1 << endl;
    else cout << res1 << ' ' << res2 << endl;






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