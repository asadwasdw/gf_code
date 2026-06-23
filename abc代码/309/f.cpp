#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=4e6+10;
const int mod=998244353;

typedef long long ll;
const int INF  = 0x3f3f3f3f3f3f3f3f;
struct cfx
{
    int a,b,c;
}cfxs[N];

vector<int>lsh;

struct{
    int l,r,mn;
}tr[N*4];

void pushup(int u){
    tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
}

void build(int u,int l,int r)
{
    tr[u]={l,r,INF};
    if(l==r)return;
    int mid = l +r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

int query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r){
        return tr[u].mn;
    }

    int mid = tr[u].l + tr[u].r>>1;

    int res =INF;
    if(l<=mid)res=min(res,query(u<<1,l,r));
    if(r>mid)res=min(res,query(u<<1|1,l,r));
    return res;
}

void modify(int u,int x,int k)
{
    if(tr[u].l==tr[u].r&&tr[u].l==x){
        tr[u].mn=min(k,tr[u].mn);
        return;
    }
    int mid =tr[u].l+tr[u].r>>1;

    if(x<=mid)modify(u<<1,x,k);
    if(x>mid)modify(u<<1|1,x,k);
    pushup(u);
}

bool cmp(cfx a,cfx b)
{
    if(a.a!=b.a)return a.a<b.a;
    if(a.b!=b.b)return a.b>b.b;
    return a.c>b.c;
}


void solve()
{

    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int h,w,d;
        cin>>h>>w>>d;
        lsh.push_back(h);
        lsh.push_back(w);
        lsh.push_back(d);

        // lsh.push_back(h+1);
        // lsh.push_back(w+1);
        // lsh.push_back(d+1);

        lsh.push_back(h-1);
        lsh.push_back(w-1);
        lsh.push_back(d-1);

        cfxs[i]={h,w,d};
    }

    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());

    int m = 0;

    for(int i=1;i<=n;i++)
    {
        cfxs[i].a=lower_bound(lsh.begin(),lsh.end(),cfxs[i].a)-lsh.begin()+1;
        cfxs[i].b=lower_bound(lsh.begin(),lsh.end(),cfxs[i].b)-lsh.begin()+1;
        cfxs[i].c=lower_bound(lsh.begin(),lsh.end(),cfxs[i].c)-lsh.begin()+1;

        int t[5];
        t[1]=cfxs[i].a;
        t[2]=cfxs[i].b;
        t[3]=cfxs[i].c;

        sort(t+1,t+3+1);
        cfxs[i].a=t[1];
        cfxs[i].b=t[2];
        cfxs[i].c=t[3];
        m=max({m,cfxs[i].a+1,cfxs[i].b+1,cfxs[i].c+1});
    }

    build(1,1,m+2);

   //for(int i=1;i<=3;i++)cout<<cfxs[i].a<<" "<<cfxs[i].b<<" "<<cfxs[i].c<<endl;
    

     sort(cfxs+1,cfxs+n+1,cmp);

     //modify(1,1,0);
    // cout<<query(1,1,2);

    for(int i=1;i<=n;i++)
    {
        int t = query(1,1,cfxs[i].b-1);
       // cout<<cfxs[i].a<<" "<<cfxs[i].b<<" "<<cfxs[i].c<<endl;
       // cout<<t<<endl;
        if(t<cfxs[i].c){
            cout<<"Yes";
            return;
        }
        modify(1,cfxs[i].b,cfxs[i].c);
    }

    cout<<"No";

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





