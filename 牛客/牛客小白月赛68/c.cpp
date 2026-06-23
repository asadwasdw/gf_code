#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
unordered_map<char,int> st;

void solve()
{

    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    double ans=0;

    for(int i=1;i<=n;i++)
    {
        double ds=0;
        st.clear();
        st[s[i]]++;
        for(int j=i+1;j<=n;j++)
        {
            char t=s[j];
            if(st[t]>1){
                ds-=(st[t]*(st[t]-1))/2;
            }
            st[t]++;
            ds+=(st[t]*(st[t]-1))/2;

            double f= ds/(j-i+1);
            //cout<<i<<" "<<j<<" "<<ds<<" " <<f <<endl;
            ans=max(f,ans);
        }
        
    }
    printf("%lf\n",ans);



}



signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
    int t;cin>>t;while(t--)
    solve();
}