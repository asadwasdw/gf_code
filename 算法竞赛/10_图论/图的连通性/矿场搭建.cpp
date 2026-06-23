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
int s[N],tt;
int n;
int dfn,num[N],low[N];
vector<vector<int>>bs(N);
int bcnt;
int root;
int ic[N];

void tarjan(int x)
{
    
    num[x]=low[x]=++dfn;
    s[++tt]=x;

    if(edg[x].size()==0)
    {
        bcnt++;
        bs[bcnt].push_back(x);
        return;
    }
    int cnt = 0;
    for(auto v:edg[x]){
        if(!num[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);

            if(num[x]<=low[v]){
                cnt++;
                if(x!=root||cnt>1)
                    ic[x]=1;
                ++bcnt;

                
                
                do{
                    bs[bcnt].push_back(s[tt]);
                }
                while(s[tt--]!=v);
                //cout<<bcnt<<" "<<x<<endl;
                bs[bcnt].push_back(x);
              //  cout<<bcnt<<" "<<x<<endl;
            }
        }
        else 
            low[x]=min(low[x],num[v]);
    }


}


void solve(int m)
{
    n=0;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
        n=max({a,b,n});
    }

    for(root=1;root<=n;root++)
    {
        int i = root;
        if(!num[i])tarjan(i);
    }
    // cout<<bcnt<<endl;
    // for(int i = 1;i<=bcnt;i++){
    //     cout<<i<<endl;
    //     for(auto v:bs[i])cout<<v<<" ";cout<<endl;
    // }

    int ans1 = 0;
    int ans2 = 1;

    for(int i=1;i<=bcnt;i++)
    {
        int cnt = 0;
        int len = bs[i].size();

        for(auto t:bs[i])if(ic[t])cnt++;

        if(!cnt)
        {
            if(len>1)ans1+=2,ans2*=len*(len-1)/2;
            else ans1++;
        }
        else if(cnt==1){
            ans1++;
            ans2*=len-1;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    {
        for(int i=1;i<=n;i++){
            edg[i].clear();
            ic[i]=0;
            dfn=0;
            num[i]=low[i]=0;
            bs[i].clear();
        }

        dfn=0;
        bcnt=0;
        root=0;
        tt= 0;



    }


}


signed main()
{
    int t;t=1;
    int T = 0;
    while(cin>>t){
        T++;
        if(t==0)break;
        printf("Case %d: ",T);
        solve(t);
    }
}
