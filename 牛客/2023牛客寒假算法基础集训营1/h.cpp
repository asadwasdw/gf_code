#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n*n-1;i++)
    {
        string s;
        cin>>s;
        int p=10;
        for(int j=0;j<=3;j++)
        {
            if(s[j]=='1')p-=1;
            if(s[j]=='2')p+=1;
        }
        sum+=p;
    }

    cout<<(long long)10*n*n-sum<<endl;
}



int main()
{
    int t;cin>>t;while(t--)
    solve();
}