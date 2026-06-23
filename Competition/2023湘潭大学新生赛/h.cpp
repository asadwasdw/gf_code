#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;

unordered_map<char,int>st;
typedef pair<int,int>PII;
map<PII,int>f;

const int N=2e3+10;


void solve()
{
    f.clear();
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    st['X']=1;
    st['T']=2;
    st['U']=3;
    int a,b,c;
    int ans=0;
    f[{0,0}]=1;
    a=b=c=0;
    for(int i=1;i<=n;i++)
    {
        int t=st[s[i]];
        if(t==1)a++;
        else if(t==2)b++;
        else c++;
      //  cout<<a<<" "<<b<<" "<<c<<endl;
       // cout<<f[{b-a,c-b}]<<"  aaaaaa"<<endl;
        ans+=f[{b-a,c-b}];
        f[{b-a,c-b}]++;
        
      //  cout<<ans<<" "<<i<<endl<<endl;
    }
    cout<<ans<<endl;
}
int main()
{
    int t;cin>>t;while(t--)
    solve();
    return 0;


}