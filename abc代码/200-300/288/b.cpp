#include<iostream>
#include<algorithm>

using namespace std;
const int N=110;
string s[N];

bool cmp(string a,string b){
    for(int i=0;i<min(a.size(),b.size());i++){
        if(a[i]!=b[i])return a[i]<b[i];
    }

    return a.size()<b.size();
}

void solve()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        s[i]=t;
    }
    
    sort(s+1,s+k+1);
    for(int i=1;i<=k;i++)cout<<s[i]<<endl;;
}


int main()
{
   // int t;cin>>t;while(t--)
    solve();
}