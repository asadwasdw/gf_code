#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=5e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int Color[N];
int w[N];
struct node{
    int l,r;
    ll sum;
    unordered_map<int,int>color;
}tr[N*4];


void pushupsum(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushupcolor(int u)
{
    tr[u].color.clear();
    for(auto t:tr[u<<1].color){
        int x=t.first;
        int y=t.second;
        tr[u].color[x]+=y;
    }

    for(auto t:tr[u<<1|1].color){
        int x=t.first;
        int y=t.second;
        tr[u].color[x]+=y;
    }
}

void build(int u,int l,int r)
{
    //cout<<u<<" "<<l<<" "<<r<<endl;
    tr[u].l=l;
    tr[u].r=r;
    if(l==r)
    {
        tr[u].color.clear();
        tr[u].color[Color[l]]++;
        tr[u].sum=w[l];
        return ;
    }
    
    int mid=l+r>>1;

    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushupsum(u);
    pushupcolor(u);
    
}

void modifysum(int u,int x,int y)
{
    if(tr[u].l==x&&x==tr[u].r){
        tr[u].sum=y;
        return;
    }

    int mid=tr[u].l+tr[u].r>>1;
    if(x<=mid)modifysum(u<<1,x,y);
    else modifysum(u<<1|1,x,y);

    pushupsum(u);
}


void modifycolor(int u,int x,int y,int z)
{
    tr[u].color[y]+=z;
    if(tr[u].l==x&&x==tr[u].r){
        return;
    }

    int mid=tr[u].l+tr[u].r>>1;
    if(x<=mid)
    {
        modifycolor(u<<1,x,y,z);
    }
    else modifycolor(u<<1|1,x,y,z);
}


ll querysum(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        return tr[u].sum;
    }

    int mid=tr[u].r+tr[u].l>>1;

    ll res=0;
    if(l<=mid)res+=querysum(u<<1,l,r);
    if(r>=mid+1)res+=querysum(u<<1|1,l,r);
    return res;
}



int querycolor(int u,int l,int r,vector<int> &c)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        int res=0;
        for(auto t:c)
        {
            if(tr[u].color.count(t)){
                res+=tr[u].color[t];
            }
        }
        return res;
    }


    int mid=tr[u].l+tr[u].r>>1;
    ll res=0;
    if(l<=mid)res+=querycolor(u<<1,l,r,c);
    if(r>=mid+1)res+=querycolor(u<<1|1,l,r,c);
    return res;
}


int lfind(int u,int r,vector<int> &c)
{
   // cout<<u<<" "<<r<<endl;
    if(tr[u].l==tr[u].r)
    {
        return querycolor(u,tr[u].l,tr[u].r,c);
    }

    int mid=tr[u].l+tr[u].r>>1;

    if(r<=mid) return lfind(u<<1,r,c);

    ll res=0;
    if(querycolor(u,mid+1,r,c)==r-mid){

        res=r-mid+lfind(u<<1,mid,c);
    }
    else 
    {
        res=lfind(u<<1|1,r,c);
    }
    return res;
}


int rfind(int u,int l,vector<int> &c)
{
    if(tr[u].l==tr[u].r)
    {
        return querycolor(u,tr[u].l,tr[u].r,c);
    }

    int mid=tr[u].l+tr[u].r>>1,res=0;

    if(l>=mid+1) return rfind(u<<1|1,l,c);

    if(querycolor(u,l,mid,c) == mid+1-l){
        res+=mid-l+1+rfind(u<<1|1,mid+1,c);
    }
    else res=rfind(u<<1,l,c);
    return res;
}




void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>Color[i];

    }

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }

    build(1,1,n);

    while(m--)
    {
        int op;
        cin>>op;
        int p,x;
        if(op==1)
        {
            cin>>p>>x;

            modifycolor(1,p,Color[p],-1);
            Color[p]=x;
            modifycolor(1,p,Color[p],1);
        }
        else if(op==2)
        {
            cin>>p>>x;
            modifysum(1,p,x);
        }
        else 
        {
            cin>>x;
            int k;
            cin>>k;
            vector<int>c;
            while(k--)
            {
                int t;
                cin>>t;
                c.push_back(t);
            }

            int l=lfind(1,x,c);
            int r=rfind(1,x,c);

            //cout<<x<<endl;
            //cout<<l<<" "<<r<<endl;
            ll ans=querysum(1,x-l+1,x+r-1);
          // cout<<x-l+1<<" "<<x+r-1<<" ";
            cout<<ans<<'\n';
        }
    }


    // for(int u=1;tr[u].l!=0;u++)
    // {
    //     cout<<u<<" "<<" "<<tr[u].sum<<endl;
    // }

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