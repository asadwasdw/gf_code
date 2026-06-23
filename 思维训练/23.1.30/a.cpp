#include<iostream>
#include<algorithm>

using namespace std;

int main()
{

    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        string s;
        cin>>s;
        long long num=0;
        for(long long i=0;i<n;i++)
        if(s[i]=='*')num++;
        long long gs=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')ans+=min(num-gs,gs);
            else gs++;
        }

        cout<<ans<<endl;
    }
        




}