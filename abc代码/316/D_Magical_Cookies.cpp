#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

vector<vector<int>>edg(N);

int h[2010][30];
int l[2010][30];
int a[2010][2010];

set<int> H[N],L[N];
int hh[N],ll[N];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            char t;
            cin>>t;
            a[i][j]=(t-'a');
            h[i][a[i][j]]++;
            l[j][a[i][j]]++;

        }
    }

    int ansh=n;
    int ansl=m;

    vector<bool>sth(N),stl(N);

    while(1)
    {
        bool xy =false;
        vector<PII>ux,uy;

        for(int i=1;i<=n;i++)
        {
            if(sth[i])continue;
            for(int j=0;j<26;j++){
                if(h[i][j]==ansl&&ansl>=2){
                    ux.push_back({i,j});
                }
            }
        }

        for(int i=1;i<=m;i++)
        {
            if(stl[i])continue;
            for(int j=0;j<26;j++){
                if(l[i][j]==ansh&&ansh>=2){
                    uy.push_back({i,j});
                }
            }
        }

        for(auto t:ux){
            sth[t.first]=true;
            xy=true;
            for(int i = 1;i<=m;i++){
                l[i][t.second]--;
            }
            ansh--;
        }


        for(auto t:uy)
        {
            xy=true;
            stl[t.first]=true;
            for(int i=1;i<=n;i++){
                h[i][t.second]--;
            }

            ansl--;
        }






        if(xy==false)break;
    }





        cout<<ansl*ansh<<endl;

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