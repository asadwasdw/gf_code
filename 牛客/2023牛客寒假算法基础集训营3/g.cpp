#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

#define int long long
typedef long long ll;

vector<char>op;

int n;
vector<int>num;
long long t;

ll qmi(int a,int b,int c)
{
    ll res=1;

    while(b)
    {
        if(b&1)res=res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res%c;
}

bool dfs(ll t,int i)
{
    //cout<<t<<" "<<i<<endl;
    if(i==n)
    {
        bool ky=false;

        if(t==num[n]){
            ky=true;
            //cout<<num[1];
            for(int i=1;i<=n-2;i++){
                cout<<num[i]<<op[i];
            }
            cout<<num[n-1]<<"="<<num[n]<<endl;

            //cout<<t<<endl;
        }
        return ky;
    }

    for(int k=1;k<=3;k++)
    {
        if(k==1)
        {
            op.push_back('+');
            if(dfs(t+num[i],i+1))return true;
            op.pop_back();
        }
        else if (k==2)
        {
            op.push_back('-');
             if(dfs(t-num[i],i+1))return true;
             op.pop_back();
        }
        else if(t>0&&num[i]>0&&k==3) 
        {
            op.push_back('#');
            int T=qmi(t,t,num[i])%num[i];
            if(dfs(T,i+1))return true;
            op.pop_back();
        }
    }
    return false;

}

void solve()
{
    string s;
    cin>>s;
    s=" "+s;
    num.push_back(0);
    op.push_back('s');
    for(int i=1;i<=s.size()-1;i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            int res =0 ;
            int j=i;
            for(;s[j]<='9'&&s[j]>='0';j++)
            {
                res=res*10+s[j]-'0';
            }
           num.push_back(res);
          // cout<<res<<endl;
            i=j-1;
        }
    }
    n=num.size()-1;
 //  cout<<num[1]<<endl;

    if(dfs(num[1],2)){

    }
    else cout<<"-1"<<endl;

}


signed main()
{
   // cout<<qmi(3,3,8)<<endl;
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}