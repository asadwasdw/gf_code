#include<iostream>
#include<algorithm>
#include<deque>
#include<unordered_map>
#include<stack>

using namespace std;


deque<int>d;
const int N = 3e5+10; 

int a[N];
int b[N];

int dp[110][11100];

int main()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];

    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(!dp[i-1][j])continue;
            //cout<<i<<" "<<j<<endl;

            if(!dp[i][j+a[i]])
            {
                dp[i][j+a[i]]=1;
            }

            if(!dp[i][j+b[i]])
            {
               dp[i][j+b[i]]=2;
            }
        }
    }

    if(dp[n][m]==0){
        cout<<"No"<<endl;
        return 0;
    }
    stack<char>s;
    int j=m;

    for(int i=n;i;i--)
    {
        if(dp[i][j]==1){
            s.push('H');
            j-=a[i];
        }
        else 
        {
            s.push('T');
            j-=b[i];
        }
    }

    cout<<"Yes"<<endl;

    while(s.size())
    {
        cout<<s.top();s.pop();
    }
}