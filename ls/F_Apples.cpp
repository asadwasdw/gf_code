#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
struct Node{
    int l,r,mx,p;
}tr[N*4];

void pushup(int u){
    tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
}

void pushdown(int u)
{
    if(tr[u].p){
        tr[u<<1].mx+=tr[u].p;
        tr[u<<1|1].mx+=tr[u].p;
        tr[u<<1].p+=tr[u].p;
        tr[u<<1|1].p+=tr[u].p;
    }
    tr[u].p=0;
}

void build(int u,int l,int r) {
    tr[u]={l,r,0,0};
    if(l==r)return;
    int mid = l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int k){
    if(l<=tr[u].l && tr[u].r<=r) {
        tr[u].p+=k;
        tr[u].mx+=k;
        return;
    }
    pushdown(u);
    int mid = tr[u].l+tr[u].r>>1;
    if(l<=mid)modify(u<<1,l,r,k);
    if(r>=mid+1)modify(u<<1|1,l,r,k);
    pushup(u);
}

int query(int u,int l,int r){
   
    if(l<=tr[u].l && tr[u].r<=r) {
        return tr[u].mx;
    }
    pushdown(u);
    int mid = tr[u].l+tr[u].r>>1;
    int res = 0;
    if(l<=mid)res = max(res,query(u<<1,l,r));
    if(r>=mid+1)res = max(res,query(u<<1|1,l,r));
    return res;
}

struct apple{
    int t,wz;
}A[N];

bool cmp(apple a, apple b)
{
    return a.t<b.t;
}


void solve()
{
    int n,d,w;
    cin>>n>>d>>w;
    int r = 0;
    for(int i=1;i<=n;i++){
        cin>>A[i].t>>A[i].wz;
        r=max(A[i].wz,r);
    }
    build(1,1,r);
    sort(A+1,A+n+1,cmp);
    int l = 1;
    int ans = 0;
    for(int r=1;r<=n;r++){
        while(l<r && A[l].t + d<=A[r].t){
          modify(1,max(1,A[l].wz - w + 1),A[l].wz,-1);
            l++;
        }
       modify(1,max(1,A[r].wz - w + 1),A[r].wz,1);
        ans = max(ans,query(1,max(1,A[r].wz - w + 1),A[r].wz));
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