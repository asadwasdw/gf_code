#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int n,m;
int a[N];
int cnt = 0;
int ask(int i, int j) {
    int ans = 0;
 	cout << "? "<< i << " " << j << endl;
    cin >> ans;
    if(ans == -1)exit(0);
    return ans;
}

int js(int x) {
    int ans = 0;
    while(x) {
        int t = x & -x;
        x -= t;
        int j = x / t, i = log2(t);
        ans += ask(i,j);
    } 
    return ans;
}


void solve()
{
    int n,l,r;
    cin >> n >> l >> r;
    
    int ans = js(r + 1) - js(l); 
    cout << "! "<< (ans % 100 + 10000000) % 100 << endl;

}


signed main()
{
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
