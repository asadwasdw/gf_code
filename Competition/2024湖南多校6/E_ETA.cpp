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
    int a, b;
    scanf("%lld/%lld", &a, &b);
    if(a < b - 1) {
        cout << "impossible";
        return ;
    }

    while(a > b*(b - 1) / 2) a *= 2, b *= 2;
    cout << b << " " << b - 1 << endl;
    b--;
    
//  cout << a << " " << b << endl;
    int x = 1;
    while((a - x) >= (b - 1)) {
        a -= x;
        b--;
        cout << x << " " << x + 1 << endl;
        x ++;
    }
    int y = x + 1;
    x--;
    while(x) {
        // cout << x << " " << a << " " << b << endl;
        while(b && a - (x-1) >= b) {
            cout << x << " " <<  y << endl;
            y ++;
            a -= x;
            b--;
        }
        x--;
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