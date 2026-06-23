#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

string s;

unordered_map<int,deque<int>>st;

int to[N][25];

void solve()
{
    int m,n;
    cin>>m>>n;
    cin>>s;
    n = s.size();
    s='1'+s;

    for(int i=1;i<=n;i++)
    {
        st[s[i]-'a'].push_back(i);
        //cout<<s[i]<<" "<<i<<endl;
    }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<25;j++)to[i][j]=0;
    // }

    for(int i=0;i<=n;i++)
    {
        int t  =  0;
        for(int j=0;j<m;j++){
            while(st[j].size()&&st[j].front()<=i)st[j].pop_front();
            if(st[j].size()==0)t=n+4;
            t=max(t,st[j].front());
        }
        if(t==0) t =n+4;
        to[i][0]= t;
          //for(int i=0;i<m;i++)cout<<*st[i].begin()<<endl;
        // {for(auto t: st[i])cout<<t<<" ";cout<<endl; }


    }

    //for(int i=1;i<=n;i++)cout<<i<<" "<<to[i][0]<<endl;


    for(int i = n;i>=0;i--)
    {
        for(int j=1;j<=20;j++)
        {
            to[i][j]=to[to[i][j-1]][j-1];
            if(to[i][j]==0){
                to[i][j] = n+5;
                continue;
            }
        }
    }

    //  for(int j = 1; j <= 20; j++){
    //     for(int i = 0; i <= n; i++){
    //         int t = to[i][j - 1];
    //         if(t <= n) to[i][j] = to[t][j - 1];
    //         else to[i][j] = n + 1;
    //     }
    // }

    // for(int i=1;i<=6;i++)
    // {
    //     for(int j=0;j<=3;j++)cout<<to[i][j]<<" ";cout<<endl;
    // }



    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        int x = l-1;
        int res=0;
        for(int i=20;i>=0;i--){

            if(to[x][i]>r)continue;
            x=to[x][i];
            res+=(1<<i);
        }
        
        cout<<res+1<<endl;
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