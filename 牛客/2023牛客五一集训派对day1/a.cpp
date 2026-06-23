#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int lastc[5];
typedef pair<string,int>PII;
vector<PII>ans;


bool cmp(PII A,PII B)
{
    string a=A.first;
    string b=B.first;

  //  cout<<a<<endl;
 
    for(int i=0;i<a.size()&&i<b.size();i++)
    {
        if(a[i]!=b[i])
        {
            return a[i]<b[i];
        }
    }
 
    return A.second>B.second;
}
 
 



void solve(int n)
{
    ans.clear();
    lastc[0]=lastc[1]=lastc[2]=0;
    string s=" ";

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        s+=c;
    }

    string T="";
    for(int i=n;i;i--)
    {
        int t=s[i]-'a'+1;

        T='0'+T;

        int cz=0;

        if(lastc[t]){

             cz=lastc[t]-i;
             
           // cout<<cz<<" "<<i<<endl;
            T[cz]=(char)(cz+'0');
        }

        lastc[t]=i;
    
        ans.push_back({T.substr(0,cz+100),i});

       //cout<<T<<" "<<i<<endl;
    }
      sort(ans.begin(),ans.end());
 //   sort(ans.begin(),ans.end(),cmp);

    for(auto t:ans)cout<<t.second<<" ";

    cout<<endl;


}


int main()
{

    int n;
    while(cin>>n)
    {
        solve(n);
    }



}