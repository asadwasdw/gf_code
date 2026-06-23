#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

struct per{
    int id,c;
    bool st[50];
}p[N];

bool cmp(per a, per b)
{
    if(a.c!=b.c){
        return a.c<b.c;
    }
    else return a.id<b.id;
}

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int c;cin>>c;
        p[i].c=c;
      //  cout<<c<<endl;
        while(c--){
            int x;
            cin>>x;
           // cout<<x<<" ";
            p[i].st[x]=true;
        }
       //cout<<endl;
        p[i].id=i;
    }
    sort(p,p+n+1,cmp);

    int res = 0;
    cin>>res;
    vector<int>ans;
    int num = 0;
    for(int i=1;i<=n;i++){
        if(num&&p[i].c>num)break;
       // cout<<p[i].id<<endl;
        if(p[i].st[res]){
            if(!num)num=p[i].c;
            ans.push_back(p[i].id);
        }
    }


    cout<<ans.size()<<endl;
    for(auto t :ans){
        cout<<t<<" ";
    }
    cout<<endl;





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