#include<iostream>
#include<algorithm>


using namespace std;


void solve()
{
    int n;cin>>n;
    string s;
    cin>>s;
    int a=0;
    int b=0;
    bool ky=false;
    for(auto t:s){
        if(t=='|')
        {
            a++;
        }
        else if(t=='*')
        {
            if(a==1)ky=true;
        }
    }

    if(ky)cout<<"in"<<endl;
    else cout<<"out"<<endl;

}


int main()
{
   // int t=1;cin>>t;while(t--)
    solve();
    return 0;
}