#include<iostream>
#include<algorithm>

using namespace std;

int d[22050];


int main()
{
    string s;
    cin>>s;
    s=" "+s;
    int x=0;
    long long ans=0;
    d[0]=1;

    for(int i=1;i<s.size();i++)
    {
        int t=s[i]-'0';
      //  cout<<x<<"---> ";
        if((x>>t&1)==0)
        {
            x+=1<<t;
        }
        else x-=1<<t;

            ans+=d[x];
            d[x]++;
            //cout<<x<<endl;
        
    }

    cout<<ans<<endl;
}