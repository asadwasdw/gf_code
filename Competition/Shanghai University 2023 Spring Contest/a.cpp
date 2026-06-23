#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int f(int l,int r,int x) { // l <= x <= r
    int cnt = 0;
    while(l <= r) {
        cnt++;
        int mid = (l + r) / 2;
        if (mid == x) break;
        if (mid < x) l = mid + 1;
        else r = mid - 1;
    }
    return cnt;
}

void solve()
{
    int l,r,x;
    cin>>l>>r>>x;
    cout<<f(l,r,x)<<endl;
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