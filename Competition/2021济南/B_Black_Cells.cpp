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

int a[N];
int b[N],c[N];
int n;
bool check(int mid) {
    for(int i = 1; i + 1 <= n; i += 2) {
        if(a[i + 1] - a[i] > mid) {
            if(n % 2 == 0) return false;
            if(i % 2 == 0) return false;
            i --;
        }
    }
    return true;
} 


void solve()
{
   
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int l = 1, r = 1e18;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
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