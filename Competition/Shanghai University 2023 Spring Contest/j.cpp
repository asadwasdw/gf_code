#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int cnt[N];

void solve()
{

    string s;
    int n;

    cin>>s;
    n=s.size();
    s=" "+s;

    if(s[1]!='('||s[n]!=')'|| n%2)
    {
        cout<<"NO"<<endl;
        return ;
    }

    int cnt1=0;
    int i=1;
    int c=0;
    for(;i<=n;i++){

        if(s[i]=='(')
        {
            cnt1++;
            c++;
            cnt[c]=0;
        }
        else 
        {
            cnt1--;
            c--;
            cnt[c]++;
            if(cnt[c]>=3)
            {
                break;
            }
        }

        if(cnt1<0)break;
    }

    //cout<<cnt1<<" "<<i<<endl;

    if(cnt1!=0||i<n){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;

    
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