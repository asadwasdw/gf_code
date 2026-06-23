#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    int m;cin>>s>>m;
    s=" "+s;
    int n=s.size()-1;

    int i=1;
    int ans=0;
    while(i<=n)
    {
        int j=m;

        for(int k=1;k<=m;k++)
        {
            int t = i;
            while(s[t]==s[t+k]&&t<=n)t++;

            j=max(j,t+k);
        }
        ans++;
        i=j;

    }

    cout<<ans<<endl;




}