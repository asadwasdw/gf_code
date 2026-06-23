#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int N=1e5+10;

int a[N];
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    map<char,int>m;
    m['m']=1;
    m['e']=2;
    m['o']=3;
    m['w']=4;

   for(int i=1;i<=n;i++)
    {
        a[i]=m[s[i-1]];
    }

    int mx=0;
    bool ky=true;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)ky=false;

        if(a[i]-mx>=2)ky=false;
        if(a[i]<mx)ky=false;
        mx=max(mx,a[i]);
    }

    if(ky&&mx==4)cout<<"YES";
    else cout<<"NO";
    cout<<endl;




}

int main()
{
  int t;cin>>t;while(t--)
  solve();

}