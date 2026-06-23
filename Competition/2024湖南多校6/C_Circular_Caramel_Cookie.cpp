#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const long double eps = 1e-6;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

ll s;
void solve()
{
    cin >> s;
    long double l = 1, r = 1e5;
    auto check = [&](long double mid){
        ll res = 0;
        ll len = sqrtl(mid * mid / 2);
        res += len * len * 4;
        while(len+1 <= (ll)mid){
            ++len;
            ll l = 1, r = mid+10;
            while (l < r)
            {
                ll m = l + r >> 1;
                if(mid >= sqrtl(len*len + m*m))l = m+1;
                else r = m;
            }
            if(mid >= sqrtl(len*len + m*m))--l;
            res += l*2*4;
        }
        return res > s;
    };
    while(r - l > eps){
        long double mid = (l + r) / 2;
        if(check(mid))r = mid;
        else l = mid;
    }
    cout << l << endl;






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(6) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}