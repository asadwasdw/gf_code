#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<char,int>mp;
int main()
{
    int n;cin>>n;

    string a,b;
    cin>>a>>b;
    int num=0;

    int cz[5];

    
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
      
            num++;
            if(num<=2)cz[num]=i;
        }
        else 
        {
            mp[a[i]]++;
        }
    }

    if(num==2)
    {
        if(a[cz[1]]==b[cz[2]]&&a[cz[2]]==b[cz[1]])cout<<"YES";
        else cout<<"NO";

    }
    else if(num==0)
    {
        for(auto t :mp)
        {
            if(t.second>=2)
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
    }
    else cout<<"NO";
}