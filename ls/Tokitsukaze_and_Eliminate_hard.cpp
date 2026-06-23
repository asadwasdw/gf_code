#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

unordered_map<int,vector<int>>edg;
int a[N];

priority_queue<PII,vector<PII>,greater<PII>>q; 
void solve()
{
    while (q.size())
    {
        q.pop();
    }
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        edg[a[i]].push_back(i);
    }

    for(auto &t:edg ) {
        if(t.second.size()) {
            q.push({t.second.back(),t.first});
            t.second.pop_back();
        }
    }

    int w = n;
    int ans = 0;
    while(w&&q.size()) {
        while(q.size()&&q.top().first > w) 
        {
            PII T = q.top();
            q.pop();
            if(edg[T.second].size()){
                q.push({edg[T.second].back(),T.second});
                edg[T.second].pop_back();
            }
        }
        PII T = q.top();
        q.pop();
        w=T.first-1;
        if(edg[T.second].size()){
            q.push({edg[T.second].back(),T.second});
            edg[T.second].pop_back();
        }
        ans++;
    }
    cout<<ans<<endl;

    for(auto &t:edg) {
        t.second.clear();
    }
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