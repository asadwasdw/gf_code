#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

struct Node{
    int l,r;
    int max1,max2,num1,num2;
}tr[N];

void pushup(Node &root,Node &lson,Node &rson) {
    unordered_map<int,int>st;

    st[lson.max1] += lson.num1;
    st[lson.max2] += lson.num2;

    st[rson.max1] += rson.num1;
    st[rson.max2] += rson.num2;
    set<int>s;
    s.insert(-1);
    s.insert(lson.max1);s.insert(lson.max2);s.insert(rson.max1);s.insert(rson.max2);

    // for(auto t:s)cout<<t<<" ";cout<<endl;

    root.max1 = *prev(s.end());
    // cout<<*prev(s.end())<<endl;
    s.erase(prev(s.end()));
    root.max2 = *prev(s.end());

    root.num1 = st[root.max1];
    root.num2 = st[root.max2];
}

void pushup(int u) {
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
int a[N];

void build(int u,int l,int r) {
   
    if(l==r) {
        tr[u]={l,r,a[l],-1,1,0};
        return;
    }
    tr[u]={l,r};

    int mid = l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    // cout<<u<<" "<<l<<" "<<r<<endl;
    pushup(u); 
     
}

Node query(int u,int l,int r) {
    Node res={0,0,-1,0,-1,0};
    Node res1={0,0,-1,0,-1,0};
    Node res2={0,0,-1,0,-1,0};

    if(l<=tr[u].l && tr[u].r<=r) {
        return tr[u];
    }
    int mid = tr[u].l+tr[u].r>>1;

    if(l<=mid)res1 = query(u<<1,l,r);
    if(r>=mid+1) res2 = query(u<<1|1,l,r);
    pushup(res,res1,res2);
    // cout<<l<<" "<<r<<res.max2<<endl;
    return res;
}
void modify(int u,int x,int y) {
    if(tr[u].l == tr[u].r &&  tr[u].l == x) {
        tr[u].max1=y;
        return;
    }
    int mid = tr[u].l+tr[u].r>>1;
    if(x<=mid) modify(u<<1,x,y);
    if(x>=mid+1) modify(u<<1|1,x,y);
    pushup(u);
}



void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--) {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)modify(1,x,y);
        else cout<<query(1,x,y).num2<<endl;
    }
    // cout<<"x"<<endl;







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