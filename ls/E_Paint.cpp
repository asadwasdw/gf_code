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

int sth[N],stw[N];
struct OP{
    int t,x,a;
}op[N];
int ans[N];

void solve()
{
    int h,w,m;
    cin >> h >> w >> m;
    for(int i=1;i<=m;i++){
        cin>>op[i].t>>op[i].a>>op[i].x;
    }
    int numh = h;
    int numw = w;

    for(int i=m;i;i--){

        if(op[i].t == 1) {
            if(sth[op[i].a]) continue;
            sth[op[i].a] = true;
            ans[op[i].x] += numw;
            numh--;
        }
        else {
            if(stw[op[i].a]) continue;
            stw[op[i].a] = true;
            ans[op[i].x] += numh;
            numw--;
        }
    }
    int cnt = h*w;
    int cnt1 = 0;
    for(int i=1;i<=2e5;i++){
        cnt -= ans[i];
        if(ans[i])cnt1++;
    }
    ans[0]=cnt;
    if(ans[0])cnt1++;
    cout<<cnt1<<endl;
    for(int i=0;i<=2e5;i++){
        if(ans[i])cout << i << " " << ans[i] <<endl;
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