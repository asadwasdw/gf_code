#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int N=2e6+10;
typedef pair <int,int> PII;

map<int,vector<PII>>ys;
long long ans=0;
long long s[N];

void jtjs(vector<int> t)
{
   if(t.size()==1||t.size()==0)return;
    sort(t.begin(),t.end());
    s[0]=t[0];
   // cout<<t[0]<<" ";
    for(long long i=1;i<t.size();i++)
    {
    //    cout<<t[i]<<" ";
        ans+=i*t[i]-s[i-1];
        s[i]=s[i-1]+t[i];
    }
    //cout<<ans<<endl;
    cout<<endl;
}



void js(int x)
{
    vector<int>l;
    vector<int>h;

    for(auto a:ys[x]){
        l.push_back(a.first);
        h.push_back(a.second);
    }
   // cout<<x<<endl;
    jtjs(l);
    jtjs(h);
}

int main()
{
    int n,m;cin>>n>>m;
    int maxys=0;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        int x;cin>>x;
        maxys=max(maxys,x);

        ys[x].push_back({i,j});
    }

    for(int i=1;i<=maxys;i++)
    {
        js(i);

    }

    cout<<ans<<endl;

    

}
