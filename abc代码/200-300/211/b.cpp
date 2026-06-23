#include<iostream>
#include<algorithm>

using namespace std;



void solve()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s4!="H"&&s3!="H"&&s2!="H"&&s1!="H"){
        cout<<"No"<<endl;
        return;
    }


      if(s4!="HR"&&s3!="HR"&&s2!="HR"&&s1!="HR"){
        cout<<"No"<<endl;
        return;
    }
      if(s4!="2B"&&s3!="2B"&&s2!="2B"&&s1!="2B"){
        cout<<"No"<<endl;
        return;
    }
      if(s4!="3B"&&s3!="3B"&&s2!="3B"&&s1!="3B"){
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
    return;
    



}
int main()
{
    solve();
}

