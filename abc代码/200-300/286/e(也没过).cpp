#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int,int>PII;
#define int long long 
const int N=310,INF=0x3f3f3f3f;
PII dp[310][310];
int w[N];


PII sum(PII a,PII b)
{
    return {a.first+b.first,a.second+b.second};
}

void init(int n)
{

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dp[i][j].first>dp[i][k].first+dp[k][j].first){
                    dp[i][j]=sum(dp[i][k],dp[k][j]);
                }
                else if(dp[i][j].first==dp[i][k].first+dp[k][j].first){
                    dp[i][j].second=max(dp[i][k].second+dp[k][j].second,dp[i][j].second);
                }
            }
        }
    }

}


signed main()
{
    int n;cin>>n;
    
	for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            dp[i][j].first=INF;
        }
    }

    for(int i=1;i<=n;i++){
		string s;
		cin>>s;
        s=" "+s;
		for(int j=1;j<=n;j++){
			if(s[j]=='Y'){
				 dp[i][j].first = 1;
				dp[i][j].second = w[j];
			}
		}
	}

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<dp[i][j].second<<" ";
    //     }
    //     cout<<endl;
    // }
    init(n);

    int m;
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;

        if(dp[a][b].first>=INF/2){
           cout<<"Impossible"<<endl;
        }
        else{
            cout<<dp[a][b].first<<" "<<dp[a][b].second+w[a]<<endl;
        }
    }

}