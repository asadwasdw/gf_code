#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    string s;
     long long a,b;
     long long n;
    cin>>n>>a>>b;
    cin>>s;

    s+=s;
     long long ans=-1;
    //cout<<s<<endl;
    for(int i=0;i<n;i++)
    {
        int cs=0;
        for(int j=0;j<n/2;j++)
        {
            if(s[i+j]!=s[i+n-j-1])cs++;
        }
        
        if(ans==-1)ans=i*a+cs*b;
        else ans=min(ans,i*a+cs*b);
    }
    cout<<ans<<endl;
}