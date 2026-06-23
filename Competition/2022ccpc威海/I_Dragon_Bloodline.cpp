#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
#define int long long 
#define endl '\n'
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,m;
bool check(int x,auto &a,auto b){
    priority_queue<__int128>q;
    for(int i=1;i<=n;i++)q.push(__int128(x)*a[i]);
    int idx = m;
    while(q.size()){
        while(idx > 0 && b[idx] == 0){
            idx--;
        }
        if (idx == 0)break;
        __int128 t = q.top();q.pop();
        
        if (t <= (1ll << (idx - 1))) {
            b[idx]--;
            continue;
        }

        __int128 tmp = min((__int128)b[idx], (t / (1ll << (idx - 1))));
        b[idx] -= tmp;
        t -= tmp * (1ll << (idx - 1));
        if (t) q.push(t);
    }
    return q.size() == 0;
}
void solve()
{


    cin>> n >> m;
    vector<int>a(n+1),b(m+1);
    for(int i=1;i<=n;i++)cin>> a[i];
    for(int i=1;i<=m;i++)cin>> b[i];
    int l = 0,r = (int)1e18;
    while(l<r){
        int mid = (l+r+1)>>1;
        if(check(mid,a,b))l = mid;
        else r = mid-1;
    }
    // cout << check(3, a, b) << ' ';
    cout<<l<<endl;



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