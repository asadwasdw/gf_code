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
int a[N];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }

    if(n==1){
        cout<<"0\n";
        return;
    }
   
    int ans = INF;

    {
        int ans1;
        int num = 0;
        for(int i=2;i<=2*n;i++) {
            if(a[i]>=a[i-1]){
                num++;
            }
            else num=0;

            if(num == n - 1) {
                ans1 = 2*n - i;
                if(ans1==n) {
                    ans1=0;
                }
                ans = min({ans,ans1,n-ans1+2});
            }
        }
    }

    {
        int ans1;
        int num = 0;
        for(int i=2;i<=2*n;i++) {
            if(a[i] <= a[i-1]){
                num++;
            }
            else num=0;

            if(num == n - 1) {
                ans1 = 2*n - i;
                if(ans1==n) {
                    ans1=0;
                }
                ans = min({ans,ans1+1,n-ans1+1});
            }
        }
    }
    if(ans==INF)ans=-1;
    cout << ans << endl;

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