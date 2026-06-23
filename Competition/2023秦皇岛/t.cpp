#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
#define SZ(x) (int)x.size()
#ifdef LOCAL
#define cin std::cin
#define cout std::cout
#endif
#ifndef LOCAL
#define endl '\n'
#endif
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
#define int long long
mt19937 rnd(random_device{}());
const int INF = 0x3f3f3f3f,N=5e5+10;
ll now; // 当前最大的/k
ll k;
int n,m;
vector<pll> toAdd; // 需要后续加入的数，/k和%k的值
int nextToAdd; // 下一个需要加入的数的下标
#define ls tr[u].l 
#define rs tr[u].r 
int idx,rt;
struct node{
	int l,r;
    int sz;
    ll val;
    int key;
    bool valid; // 该点是否有效
    int cnt; // 子树valid的cnt
	int op; // 0 nothing 1 all valid 2 all unvalid
}tr[N];
void calc(int u,int op){
    if(op==1) tr[u].cnt=tr[u].sz,tr[u].valid=1;
    else if(op==2) tr[u].cnt=0,tr[u].valid=0;
    tr[u].op=op;
}
void pushup(int u){
	tr[u].sz=tr[ls].sz+tr[rs].sz+1;
    tr[u].cnt=tr[ls].cnt+tr[rs].cnt+tr[u].valid;
}
void pushdown(int u){
	if(tr[u].op){
		if(ls) calc(ls,tr[u].op);
		if(rs) calc(rs,tr[u].op);
		tr[u].op=0;
	}
}
int new_node(ll v,bool valid){
	idx++;
	tr[idx]={0,0,1,v,(int)rnd(),valid,valid,0};
	return idx;
}
int merge(int a,int b){
	if(!a||!b) return a+b;
	pushdown(a),pushdown(b);//下传懒标记,否则就合并错了
	if(tr[a].key<tr[b].key){
		tr[a].r=merge(tr[a].r,b);
		pushup(a);
		return a;
	}
	else{
		tr[b].l=merge(a,tr[b].l);
		pushup(b);
		return b;
	}
}
void splitbysize(int u,int k,int &x,int &y){//分割后，x是左树的根，y是右树的根，左树大小为k
	if(!u) x=y=0;
	else{
		pushdown(u);//下传懒标记,否则分割会出错
		if(k<=tr[ls].sz) y=u,splitbysize(tr[u].l,k,x,tr[u].l);
		else x=u,splitbysize(tr[u].r,k-tr[ls].sz-1,tr[u].r,y);
		pushup(u);
	}
}
void splitByValidSize(int u,int k,int &x,int &y){//分割后，x是左树的根，y是右树的根，左树大小为k
	if(!u) x=y=0;
	else{
		pushdown(u);//下传懒标记,否则分割会出错
		if(k<=tr[ls].cnt) y=u,splitByValidSize(tr[u].l,k,x,tr[u].l);
		else x=u,splitByValidSize(tr[u].r,k-tr[ls].cnt-tr[u].valid,tr[u].r,y);
		pushup(u);
	}
}
void splitbyval(int u,ll k,int &x,int &y){//分割后，x是左树的根，y是右树的根，左树都小于等于k，右树都大于k
	if(!u) x=y=0;
	else{
        pushdown(u);//下传懒标记,否则分割会出错
		if(tr[u].val<=k) x=u,splitbyval(tr[u].r,k,tr[u].r,y);
		else y=u,splitbyval(tr[u].l,k,x,tr[u].l);
		pushup(u);
	}
}
void insert(ll a,bool valid){
	int x,y;
	splitbyval(rt,a,x,y);
	rt=merge(merge(x,new_node(a,valid)),y);
}
void dfsTree(int u){
    if(u) pushdown(u);
    if(ls) dfsTree(ls);
    if(u){
        cout<<"[val valid?]:"<<tr[u].val<<" "<<tr[u].valid<<" \n";
        cout<<tr[u].sz<<" "<<tr[u].cnt<<endl;
    }
    if(rs) dfsTree(rs);
}
void debugTree(int u){
    // cout<<"Tree:\n";
    // dfsTree(u);
    // cout<<"end\n";
}
ll queryValid(int u,int k){ // valid 的第 k 大 
    k = tr[u].cnt - k + 1;
    while(1){
        pushdown(u);//下传懒标记,否则分割会出错
		if(k<=tr[ls].cnt) u=tr[u].l;
		else if(k==tr[ls].cnt+tr[u].valid){
            //cout<<"valid "<<k<<"th:"<<" "<<tr[u].val<<"\n";
            return tr[u].val;
        }
		else k-=tr[ls].cnt+tr[u].valid,u=tr[u].r;
	}
}
ll queryUnValid(int u,int k){ // unvalid 的第 k 大 
    k = (tr[u].sz - tr[u].cnt) - k + 1;
    
    while(1){
        pushdown(u);//下传懒标记,否则分割会出错
		if(k<=tr[ls].sz - tr[ls].cnt) u=tr[u].l;
		else if(k==tr[ls].sz - tr[ls].cnt+(!tr[u].valid)){
            //cout<<"unvalid "<<k<<"th:"<<" "<<tr[u].val<<"\n";
            return tr[u].val;
        } 
		else k-=tr[ls].sz - tr[ls].cnt+(!tr[u].valid),u=tr[u].r;
	}
}
void add(ll tar,bool valid){ // /k=tar的加进去
    while(nextToAdd<toAdd.size()&&toAdd[nextToAdd].fi==tar){
        insert(toAdd[nextToAdd].se,valid);
        nextToAdd++;
    }
}
void makeLastTUnvalid(int t){
    int rem=tr[rt].cnt;
    int x,y;
    splitByValidSize(rt,rem-t,x,y);
    calc(y,2);
    rt=merge(x,y);
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        ll tmp;
        cin>>tmp;
        ll div;
        if(tmp<0) div=(tmp-k+1)/k;
        else div=tmp/k;
        ll rem=tmp-div*k;
        toAdd.emplace_back(div,rem);
    }
    sort(toAdd.begin(),toAdd.end(),[](const pll& a,const pll& b){
        if(a.fi!=b.fi) return a.fi>b.fi;
        return a.se>b.se;
    });
    now=toAdd[0].fi;
    add(now,true);
    debugTree(rt);
    while(m--){
        char c;
        cin>>c;
        if(c=='C'){
            ll t;
            cin>>t;
            // - k  t times
            int rem=tr[rt].cnt;
            if(rem>=t){
                makeLastTUnvalid(t);
                continue;
            }
            t-=rem;
            now--;
            calc(rt,1);
            while(t){
                if(nextToAdd>=toAdd.size()){
                    ll times=t/tr[rt].sz;
                    now-=times;
                    t-=times*tr[rt].sz;
                    if(t) makeLastTUnvalid(t);
                    break;
                }
                ll nextKs = toAdd[nextToAdd].fi;
                ll maTimes = now-nextKs;
                if(maTimes*tr[rt].sz>=t){
                    ll times=t/tr[rt].sz;
                    now-=times;
                    t-=times*tr[rt].sz;
                    if(t) makeLastTUnvalid(t);
                    break;
                }
                t-=maTimes*tr[rt].sz;
                now-=maTimes;
                add(now,true);
            }
            
        }
        else{
            int x;
            cin>>x;
            // 第 x 大
            if(tr[rt].cnt>=x){//在树内
                cout<<queryValid(rt,x)+now*k<<endl;
                continue;
            }
            // 否则先把now - 1 的加进去
            add(now-1,false);
            debugTree(rt);
            // 再看看在不在树内
            if(tr[rt].sz>=x){ //在树内
                cout<<
                queryUnValid(rt,x-tr[rt].cnt)+(now-1)*k
                <<endl;
                continue;
            }
            // 在树外
            int tarindex = x-tr[rt].sz-1+nextToAdd;
            cout<<toAdd[tarindex].fi*k+toAdd[tarindex].se<<endl;
        }
        debugTree(rt);
    }
}
signed main()
{
#ifndef LOCAL
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#endif
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;
}