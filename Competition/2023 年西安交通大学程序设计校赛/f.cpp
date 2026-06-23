#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

bool st[110][5];


void print(int x)
{
    //cout<<x<<endl;
    if(x%2)cout<<"Nocriz"<<endl;
    else cout<<"Sheauhaw"<<endl;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=3*n-3;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b==1||b==3)
        {
            if(st[a][2]){
                print(i);
                return;
            }
            st[a][b]=1;
        }
        else 
        {
            
            if(st[a][1]||st[a][3])
            {
                print(i);
                return;
            }
            st[a][b]=1;
        }
    }

    for(int i=1;i<=3;i++)cout<<st[1][i]<<endl;



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