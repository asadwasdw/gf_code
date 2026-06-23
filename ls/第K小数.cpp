#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int n,m;
int a[N];
vector<int>nums;

struct Node{
    int l,r;
    int cnt ;
}tr[N<<5];

int root[N],idx;
int find(int x)
{
    return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
}

int build(int l,int r)
{
    int p = ++idx;
    if(l==r)return p;
    int mid = l +r>>1;
    tr[p].l = build(l,mid),tr[p].r=build(mid+1,r);
    return p;
}

int insert(int p,int l,int r ,int x){
    int q = ++ idx;
    tr[q]=tr[p];
    if(l==r){
        tr[q].cnt++;
        return q;
    }
    int mid = l + r>>1;
    if(x<=mid)tr[q].l = insert(tr[p].l,l,mid,x);
    else tr[q].r = insert(tr[p].r,mid+1,r,x);
    tr[q].cnt = tr[tr[q].l].cnt+tr[tr[q].r].cnt;
    return q;
}


int query(int p,int q,int l,int r,int k){
    if(l==r)return r;
    int cnt = tr[tr[q].l].cnt-tr[tr[p].l].cnt;
    int mid  = l+r>>1;
    if(k<=cnt)return query(tr[p].l,tr[q].l,l,mid,k);
    else return query(tr[p].r,tr[q].r,mid+1,r,k-cnt);
}


void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        nums.push_back(a[i]);
    }

    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());

   // root[0]=build(0,nums.size()-1);

    for(int i=1;i<=n;i++){
        root[i]=insert(root[i-1],0,nums.size()-1,find(a[i]));
    }


    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<nums[query(root[l-1],root[r],0,nums.size()-1,k)]<<endl;
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