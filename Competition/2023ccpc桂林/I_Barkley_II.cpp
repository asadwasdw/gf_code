#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,m;
struct query{
    int l,r,w,ans;
};

vector<query> q;
int last[N],a[N];

bool cmp(query a,query b) {
    return a.r < b.r;
}

int tr[N];

void add(int x,int k) {
    for(int i=x; i<=n;i += i&-i) tr[i]+=k;
}

int sum(int x){
    int res = 0;
    for(int i = x;i; i -= i&-i) res += tr[i];
    return res; 
}

int que(int l,int r) {
    return sum(r)-sum(l-1);
}



void solve()
{

    cin>>n>>m;
    unordered_map<int,int>st;
    set<int>s;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        q.push_back({last[a[i]]+1, i-1,0,a[i]});
        last[a[i]] = i;
        st[a[i]]++;
        s.insert(a[i]);
    }

    
    
    int x=1;
    while(st[x])x++;
    

    for(auto t:s){
        q.push_back({last[t]+1,n,0,t});
        last[t]=0;
    }
    q.push_back({1,n,0,x});

    // for(auto t:q){
    //    if(t.r>=t.l) cout<<t.l<<" "<<t.r<<" "<<t.ans<<endl;
    // }
   
    s.insert(x);
    sort(q.begin(),q.end(),cmp);



    int R = 0;
    int res = -INF;
    for(auto t:q) {
        int l = t.l;
        int r = t.r;
        if(l>r)continue;
        while(R<r){
            R++;
            if(last[a[R]])add(last[a[R]],-1);
            last[a[R]]=R;
            add(last[a[R]],1);
        }

        res = max(res, que(l,r) - t.ans);
    }

    cout<<res<<"\n";

    for(auto t:s){
        if(last[t])add(last[t],-1);
        last[t]=0;
    }

    q.clear();
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