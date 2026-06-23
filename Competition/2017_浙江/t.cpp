#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N],b[N],pa[N],pb[N];
int pre[N];

void build(int root,int la,int lb,int &len){
    if(len == 0) return ;

    if(a[la] == b[lb]){
        pre[a[la]] = root;
        int ls_la = la + 1, ls_lb = lb+1,ls_len = len -1;
        build(a[la],ls_la,ls_lb,ls_len);

        if(ls_len + 1 < len){
            int rs_root = a[la + ls_len + 1] , rs_la = la+ls_len + 2,rs_lb = lb+ls_len+2;
            int rs_len = len - ls_len - 2;
            pre[rs_root] = root;
            build(rs_root,rs_la,rs_lb,rs_len);
            len = ls_len + rs_len + 2;
        }
    }
    else {
        pre[a[la]] = root;
        pre[b[lb]] = root;

        int ls_la = la+1,ls_ra = pa[b[lb]] - 1;
        int ls_len = ls_ra - ls_la + 1;
        int ls_lb = pb[a[la]]+1;
        build(a[la], ls_la, ls_lb, ls_len); 


        int rs_lb = lb + 1,rs_rb = pb[a[la]] -1;
        int rs_len = rs_rb - rs_lb + 1;
        int rs_la = pa[b[lb]]+1;
        build(b[lb], rs_la, rs_lb, rs_len); 
        
        len = ls_len + rs_len + 2;
        return ;
    }
}

void solve()
{
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pa[a[i]] = i;
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
        pb[b[i]] = i;
    }

    build(0,1,1,n);

    for(int i = 1; i<=n;i++){
        printf("%d%c", pre[i], i==n?'\n':' ');
    }

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}