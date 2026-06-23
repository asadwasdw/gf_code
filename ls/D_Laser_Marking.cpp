#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

#define double long double

//vector<vector<int>>adj(N);

int a[N], b[N],c[N],d[N];

double len(int x1, int y1, int x2, int y2) {
    int x = x1 - x2;
    int y = y1 - y2;
    return sqrtl(x * x + y * y);
}
void solve()
{
    int n, t, s;
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    double ans = INFll;
    for(int i = 0; i < (1 << n); i ++) {
       
        int num[8];
        for(int j = 0; j < 8; j ++) num[j] = j;


        do{
            int x = 0, y = 0;
            double res = 0;
            for(int j = 1; j <= n; j ++) {
                int J = num[j] - 1;

                if(((i >> J) & 1) == 0) {
                    res +=  len(x, y, a[J], b[J]) /s;
                    x = c[J], y = d[J];
                } else {
                    res +=  len(x, y, c[J], d[J])/s;
                    x = a[J], y = b[J];
                }
                res +=  len(a[J],b[J],c[J],d[J])/t;
            }
            ans = min(res, ans);

        }while(next_permutation(num + 1, num + n + 1));
    }
    cout << ans << endl;








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