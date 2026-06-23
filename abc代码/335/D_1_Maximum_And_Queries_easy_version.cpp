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
int a[N],b[N];

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    while(q--){
        int k; cin >> k;
        for(int i=1;i<=n;i++)b[i]=a[i];

        int ans = 0;
        for(int i=60;~i;i--){
            int t = 1ll << i;
            int cnt = 0;
            for(int i=1;i<=n && cnt<=k;i++){
                if(!(b[i]&t)) {
                    int w = t-(b[i]%t);
                    cnt += w; // 如果每个数都是0，那么需要cnt =（1<<60)*n > longlong
                }
            }

            if(k>=cnt){
                ans+=t;
                k-=cnt;
                for(int i=1;i<=n;i++){
                    if(!(b[i]&t)) {
                        b[i]-=b[i]%t;
                        b[i]+=t;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

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