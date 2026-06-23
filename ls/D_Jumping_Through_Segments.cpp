#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n;
PII a[N];


bool check(int mid) {
    int t = 0;
    int l = 0,r = 0;
    for(int i = 1;i<=n;i++) {
        r = min(r+mid,a[i].second);
        l = max(l-mid,a[i].first);
        if(l>r){
            return false;
        }
    }

    return true;
}

void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
    }

    int l = 0, r = INF*2ll;
    while(l<r) {
        int mid = l + r>> 1;
        if(check(mid)) r= mid;
        else l = mid+1;
    }
    cout << l << endl;

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