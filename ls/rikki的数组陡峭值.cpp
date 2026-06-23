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


void solve()
{
    int l = 0 , r =INFll;
    int ans  = 0;
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int L,R;
        cin>>L>>R;
        if(l>=r){
            if(L>l) {
                ans+=L-l;
                l=r=L;
            }

            if(R<r){
                ans+=r-R;
                r=l=R;
            }
        }
        else {
            int l1=max(l,L);
            int r1=min(R,r);
            if(l1>=r1){
                ans+=l1-r1;
                if(L>=r)l=r=L;
                else l=r=R;
            }
            else l=l1,r=r1;
        }
        // cout<<l<<" "<<r<<endl;
    }

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}