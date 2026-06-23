#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


// double a[N][N];
// int st[N];

void solve()
{

    int n;
    cin>>n;
    long double b;
    cin>>b;

  // cout<<b<<endl;

    vector<int>st(n+10,0);
    vector<vector<long double>>a(n+10,vector<long double>(n+10,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }


    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";cout<<endl;
    // }

    if(n==1)
    {
        cout<<"kono jinsei, imi ga nai!"<<endl;
        return ;
    }

 
    for(int i=1;i<=n;i++)
    {
        if(st[i]==0){

            int x=i;
            while(1)
            {
                if(st[x])
                {
                    if(x!=i)
                    {
                        //cout<<i<<" "<<x<<endl;
                        cout<<"hbxql"<<endl;
                        return ;
                    }
                    break;
                }
                
                st[x]=true;
                int ans=-1;
                long double w=-10;
                for(int i=1;i<=n;i++)
                {
                    if(i==x)continue;
                    if(a[x][i]>=b&&a[x][i]>w)
                    {
                        ans=i;
                        w=a[x][i];
                    }
                }

                //cout<<x<<" "<<ans<<endl;

                if(ans==-1){
                    cout<<"hbxql"<<endl;
                    return ;
                }
               
                x=ans;
            }

    
        }
    }



    for(int i=1;i<=n;i++)if(st[i]==false)
    {
        cout<<"hbxql"<<endl;
        return ;
    }

     cout<<"wish you the best in your search"<<endl;




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