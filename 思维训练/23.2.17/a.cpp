#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=2e5+10;

int s1[N],t1[N];
void solve()
{
    int n;cin>>n;

    string s,t,ss,tt;
    int cnt1=0;
    int cnt2=0;
    cin>>s>>t;

    for(int i=0;i<n;i++)
    {
        if(s[i]!='b'){
            ss+=s[i];
            s1[cnt1++]=i;
        }

        if(t[i]!='b'){
            tt+=t[i];
            t1[cnt2++]=i;
        }
    }

    if(ss!=tt){
      //  cout<<ss<<" "<<tt<<endl;
        cout<<"NO"<<endl;
        return;
    }

    int ky=true;

    for(int i=0;i<ss.size();i++){
        if(ss[i]=='a'){
            if(t1[i]<s1[i]){
                ky=false;
                break;
            }
        }
        else{
            if(t1[i]>s1[i]){
                ky=false;
                break;
            }
        }
    }

    if(ky)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}