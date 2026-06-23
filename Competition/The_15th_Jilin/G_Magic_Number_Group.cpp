#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int p[N],cnt,st[N];

vector<int>num[N];
int a[N];
int len;

void init(){
    
    for(int i=2;i<N;i++){
        if(st[i]==0){
            ++cnt;
            p[cnt]=i;
        }

        for(int j=1;j<=cnt&&p[j]*i<N;j++){
            st[p[j]*i]=true;
            if(i%p[j]==0)break;
        }
    }
}

void js(int x,int id){

    for(int i=1;p[i]<=x;i++)
    {
        if(!st[x]){
            num[id].push_back(x);
            return;
        }
        if(x%p[i]==0){
            //cout<<p[i]<<endl;
            num[id].push_back(p[i]);
            while(x%p[i]==0){
                x/=p[i];
            }
        }
    }
}

int ans[N];

struct query
{
    int l,r;
    int id;
}q[N];

int get(int x)
{
    return (x-1)/len+1;
}

bool cmp(query a,query b){
    if(get(a.l)==get(b.l))return a.r<b.r;
    return get(a.l)<get(b.l);
}
int res = 0;
int gs[N];
int gsdgs[N];

void add(int x){
    for(auto t:num[x]){
        gsdgs[gs[t]]--;
        gs[t]++;
        gsdgs[gs[t]]++; 
        res = max(res,gs[t]);
    }
}

void j(int x){
    for(auto t:num[x]){
        gsdgs[gs[t]]--;
        if(gsdgs[gs[t]]==0&&res==gs[t])res--;
        gs[t]--;
        gsdgs[gs[t]]++; 
    }
}

void solve()
{

    int n,m;cin>>n>>m;
    len = max((int)sqrt(n),1ll);
    for(int i=1;i<=n;i++){
        cin>>a[i];
         js(a[i],i);
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<a[i]<<" ";
    //     for(auto t:num[i])cout<<t<<" ";cout<<endl;
    // }

    for(int i=1;i<=m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }

    sort(q+1,q+m+1,cmp);

    int l=1,r=0;

    for(int i=1;i<=m;i++){

        while(r<q[i].r)add(++r);
        while(l>q[i].l)add(--l);

        while(r>q[i].r)j(r),r--;
        while(l<q[i].l)j(l),l++;

        //cout<<q[i].id<<endl;

        ans[q[i].id]=res;
    }

   // cout<<gs[3]<<endl;

    //cout<<l<<" "<<r<<endl;

    for(int i=1;i<=m;i++)cout<<ans[i]<<endl,ans[i]=0;


    while(l<=r){
        j(l);
        l++;
    }
    
    res = 0;
    for(int i=1;i<=n;i++){
        num[i].clear();
    }

    //  memset(gs,0,sizeof gs);
    //  memset(gsdgs,0,sizeof gsdgs);
    // memset(q,0,sizeof q);












}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    init();
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}