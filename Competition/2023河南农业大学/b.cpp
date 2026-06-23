#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


string op;
int w[N];

struct node{
    int l,r;
    int ch[30][2];
}tr[N<<2];

void pushup(node &t,node &l,node &r){

    for(int i=0;i<30;i++)
    {
        t.ch[i][0]=r.ch[i][l.ch[i][0]];
        t.ch[i][1]=r.ch[i][l.ch[i][1]];
    }
}

void pushup(int u)
{
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}


void build(int u,int l,int r)
{

    tr[u]={l,r};
    if(l==r){
        int t = w[l];
        for(int i=0;i<30;i++){
            int T = t>>i&1;
            if(op[l]=='|'){
                tr[u].ch[i][0]=T|0;
                tr[u].ch[i][1]=T|1;
            }
            if(op[l]=='&'){
                tr[u].ch[i][0]=T&0;
                tr[u].ch[i][1]=T&1;
            }
            if(op[l]=='^'){
                tr[u].ch[i][0]=T^0;
                tr[u].ch[i][1]=T^1;
            }
        }
        return ;
    }

    int mid = l+r>>1;

    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}



void modify(int u,int x,int t)
{
    if(tr[u].l==tr[u].r&&tr[u].l==x){

        for(int i=0;i<30;i++){
            int T = t>>i&1;
            if(op[x]=='|'){
                tr[u].ch[i][0]=T|0;
                tr[u].ch[i][1]=T|1;
            }
            if(op[x]=='&'){
                tr[u].ch[i][0]=T&0;
                tr[u].ch[i][1]=T&1;
            }
            if(op[x]=='^'){
                tr[u].ch[i][0]=T^0;
                tr[u].ch[i][1]=T^1;
            }
        }

        return ;
    }

    int mid =tr[u].l+tr[u].r>>1;

    if(x<=mid)modify(u<<1,x,t);
    if(x>=mid+1)modify(u<<1|1,x,t);
    pushup(u);
}


node query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r){
        return tr[u];
    }

    int mid =tr[u].l+tr[u].r>>1;
    
    if(r<=mid)return query(u<<1,l,r);
    else if(l>=mid+1) return query(u<<1|1,l,r);
    else 
    {
        node res;
        node L= query(u<<1,l,mid);
        node R =query(u<<1|1,mid+1,r);

        pushup(res,L,R);
        return res;
    }

}



void solve()
{
    int n;cin>>n;
    cin>>op;
    op=" "+op;

    for(int i=1;i<=n;i++)cin>>w[i];

    build(1,1,n);




    int m;
    cin>>m;
    while(m--){
        int op,x,l,r;
        cin>>op>>x>>l;
        if(op==2){
            cin>>r;

            node res =  query(1,l,r);

            int ans =0;
            for(int i=0;i<30;i++)
            {
                int t = x>>i&1;

                ans+= res.ch[i][t]<<i;
            }

            cout<<ans<<endl;


        }
        else 
        {
            modify(1,x,l);
        }
    }

  //  cout<<op<<endl;

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