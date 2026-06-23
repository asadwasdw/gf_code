#include<bits/stdc++.h>

using namespace std;

const int N =3e6+10;
int num[50];

int f[N];

int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}

int main()
{

    string s;
      cin>>s;
    int n=s.size();

    for(int i=1;i<=n+5;i++)f[i]=i;
  
    s=" "+s;
    stack<int>z;
    for(int i=1;i<=n;i++)
    {
       // cout<<i<<endl;
        //cout<<s[i]-'a'<<endl;
        if(num[s[i]-'a']){
            cout<<"No"<<endl;
            return 0;
        }
        
        if(s[i]>='a'&&s[i]<='z')num[s[i]-'a']++;
        else if(s[i]=='('){
            f[i]=find(i+1);
            z.push(i);
        }
        else 
        {
            int last =z.top();z.pop();
            f[i]=i+1;
            for(int j=last+1;j<=i;j++)
            {
                if(find(j)==j)
                {
                   // cout<<j<<endl;
                    num[s[j]-'a']--;
                    f[j]=j+1;
                }
                else {
                    j=find(j)-1;
                }
            }
            
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}