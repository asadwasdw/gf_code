#include<iostream>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;


bool ischar(char t)
{
    if(t>='A'&&t<='Z')return true;
    return false;
}




void solve()
{
string ans;
string ans2;
string ans3;
string ans4;
    string s;
    cin>>s;
    if(s.size()==1&&s[0]=='0'){
        cout<<"0"<<endl;
        return;
    }
    reverse(s.begin(),s.end());
    int n=s.size();
    s=" "+s;
    for(int j=0;j*4<=n;j++)
    {
        if(j==1&&j*4+1<=n)ans+='W';
        if(j==2&&j*4+1<=n)ans+='Y';
        for(int i=1;j*4+i<=n&&i<=4;i++)
        {
            if(i==2)ans+='T';
            if(i==3)ans+='B';
            if(i==4)ans+='K';
            ans+=s[j*4+i];
            //cout<<s[j*4+i]<<" ";
        }
    }

    reverse(ans.begin(),ans.end());
   //cout<<ans<<endl;
    ans2+=ans[0];
    for(int i=1;i<ans.size();i++)
    {
        if((ans[i]=='T'||ans[i]=='B'||ans[i]=='K')&&(ans[i-1]=='0'))continue;
        ans2+=ans[i];
    }

 cout<<ans2<<endl;

    bool yl=false;
    bool yfl=false;

    for(int i=ans2.size()-1;i>=0;i--)
    {
        if(ans2[i]=='0'){
            if(yl)continue;
            if(!yfl)continue;
            yl=true;
           // yfl=false;
        }
        else if(ans2[i]<='9'&&ans2[i]>'0'){
            yl=false;
            yfl=true;
        }
     //   cout<<i<<endl;
        ans3+=ans2[i];
    }

    reverse(ans3.begin(),ans3.end());

    while(ans3.size()>1&&ans3.back()=='0'){
        ans3.pop_back();
    }

  cout<<ans3<<endl;

    for(int i=0;i<ans3.size();i++)
    {
        if(ans3[i]=='W'&&ans3[i-1]=='Y')continue;
        if(ans3[i]=='0')
        {
            if(ischar(ans3[i-1])&&ischar(ans3[i+1]))continue;
        }
        ans4+=ans3[i];
    }
   // cout<<ans4.size()<<endl;
    cout<<ans4<<endl;
  
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
    return 0;
   
}