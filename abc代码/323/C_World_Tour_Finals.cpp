#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

bool cmp(PII a,PII b){
    if(a.first!=b.first)return a.first>b.first;
    return a.second<b.second;
}
int a[N];
vector<PII>q;
string ss[N];
int w[N];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int t;cin>>t;
        q.push_back({t,i});
        a[i]=t;
    }
    int mx1 = 0;
    int mx2 = 0;

    for(int i=1;i<=n;i++){
        string s;cin>>s;
        s = " "+s;
        w[i]=i;
        for(int j=1;j<=m;j++)if(s[j]=='o')w[i]+=a[j];
        ss[i] = s;
        
        if(w[i]>=mx1){
            mx2 = mx1;
            mx1=w[i];
        }
        else if(w[i]>mx2){
            mx2 = w[i];
        }

        
    }

    sort(q.begin(),q.end(),cmp);

    for(int i=1;i<=n;i++){

        int ans = 0;

    
        for(auto t :q){
            if(w[i]>=mx1)break;
            if(ss[i][t.second]=='x'){
                ans++;
                w[i]+=t.first;
            }
        }
        cout<<ans<<endl;
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