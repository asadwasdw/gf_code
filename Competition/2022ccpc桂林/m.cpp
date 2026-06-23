#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
#define int long long
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int tr[N];
void add(int x){
    for(;x<=N;x+=(x&-x))tr[x]++;
}
int get(int x){
    int res = 0;
    for(;x;x-=(x&-x))res+=tr[x];
    return res;
}
int a[N];
void solve()
{
    deque<int>q;
    int n,m;cin>> n >> m;
    int now = 0;
    int p = (n-1)*(n-2)/2;p%=10;
    for(int i=1;i<=n;i++)cin>> a[i],q.push_back(a[i]);
    for(int i=n;i;i--){
    
        now += get(a[i]);
        add(a[i]);
    }
    cout<<now<<endl;
    now%=10;
    
    string s;cin>> s;
    s = " "+s;
    int st = 0;
    for(int i=1;i<=m;i++){
        int t;
        if(st){
            t = q.back();q.pop_back();
        }else{
            t = q.front();q.pop_front();
        }
     
        if(s[i]=='R'){
            now = now - t + 1 + n*10;
            now %=10;
            now = p-now+100;
            now %= 10;
            now += n-t;
            now%=10;
        }else{
            now = now -t+1+n*10;
            now %=10;
            now += n-t;
            now %= 10;

        }
        cout<<now;
        if(s[i]=='R')st = 1-st;
        if(st)q.push_front(t);
        else q.push_back(t);
        
        
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