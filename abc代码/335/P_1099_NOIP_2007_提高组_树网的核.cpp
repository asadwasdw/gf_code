#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,k;

int h[N],ne[N],w[N],e[N],idx;

void add(int a,int b,int c){
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int pre[N];
int dis[N];
int bfs(int root) {
    queue<int>q;
    q.push(root);
    memset(dis,0x3f,sizeof dis);
    dis[root] = 0;

    while(q.size()){
        int u = q.front();
        q.pop();

        for(int i=h[u];~i;i=ne[i]) {
            int v = e[i];
            if(dis[v]!=INF)continue;
            dis[v] = dis[u] + w[i];
            pre[v] = u;
            q.push(v);
        }
    }
    
    for(int i=1;i<=n;i++){
        if(dis[root]<dis[i]){
            root=i;
        }
    }
    return root;
}
bool iszj[N];
int zj[N],cnt;
int mxfz[N];

int dfs(int u,int fa){
    int res = 0;
    for(int i=h[u];~i;i=ne[i]) {
        int v=e[i];
        if(v==fa)continue;
        if(iszj[v])continue;

        res = max(res, dfs(v,u)+w[i]);
    }
    return res;
}

void solve()
{
    memset(h,-1,sizeof h);
    cin >> n >> k;

    for(int i=1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }

    int q = bfs(1);
    int p = bfs(q);
    int length = dis[p];
    // cout << p << " " << q << endl;

    while(p!=q){
        zj[++cnt] = p;
        p=pre[p];
    }
    zj[++cnt] = p;

    for(int i=1;i<=cnt/2;i++){
        swap(zj[i],zj[cnt-i+1]);
    }


    for(int i=1;i<=cnt;i++) {
        iszj[zj[i]] = true;
        // cout << zj[i] <<" "<<dis[zj[i]] << endl;
    }

    for(int i=1;i<=cnt;i++) {
        mxfz[i] = dfs(zj[i],-1);
    }
  

    int l = 1,r = 1;
    int ans = INF;
    multiset<int>st;
    st.insert(mxfz[1]);

    for(;l<=cnt;l++) {
        while(r<cnt&&dis[zj[r+1]]-dis[zj[l]]<=k)r++,st.insert(mxfz[r]);
        ans=min(ans,max({dis[zj[l]],length-dis[zj[r]],*st.rbegin()}));
        st.erase(st.find(mxfz[l]));
        // cout << l<<" " << r<<endl;
    }
    cout << ans << endl;


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