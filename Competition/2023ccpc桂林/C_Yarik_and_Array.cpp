#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

#define int long long
int a[N];

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=a[1];
    int ans = a[1],res = 0;
    for(int i=1;i<=n;i++){
        if(abs(a[i])%2 == abs(a[i-1])%2 || res<0) {
           
            res = a[i];
        }
        else res+=a[i];
        if(i!=1)ans = max(ans,res);
    }
   
    cout<<ans<<endl;

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