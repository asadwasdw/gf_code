#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

const string FG = "\n         ------------------------  \n";

#define _for(i, a, b) for(int i = a; i <= b; i ++) 

int main() {

	
	string s, ss;
// int i = 1;  while(true) {  //  system("pause");
	_for(i, 1, 5) {
	Sleep(1000);
		
		s = to_string(i);
		// if(i < 10) s = "0" + s;
		
		s = "./Data/" + s;
		
		ss = "case.exe > " + s + ".in";
		
		system(ss.c_str());
		cout << "case ok" << endl; 

		
		
		ss = "std.exe < " + s +".in > " + s + ".out";
		system(ss.c_str());
		cout << "std ok" << endl; 
		
		ss = "std.exe > std.txt < " + s +".in";
		system(ss.c_str());
		ss = "bf.exe > bf.txt < " + s + ".in";
		system(ss.c_str());
		cout << "bf&std ok" << endl;
		
		ss = "fc std.txt bf.txt";

		if(system(ss.c_str())) {
			cerr << " WA !!!!!!   "  << i << endl;
//			cout << "case :" << endl;
//			ss = "type " + s + ".in";   /// ������� .in �ļ� 
//			system(ss.c_str());
			cout << endl << "bf : " << endl;
			system("type bf.txt");
			cout << endl << "std : " << endl;
			system("type std.txt");
			break;
		}
		
		// cout << endl << "bf : " << endl;
		// system("type bf.txt");
		// cout << endl << "std : " << endl;
		// system("type std.txt");
		cout << i << FG << endl;
	}
	cout << "\nfinish !!!" << endl;
	
	

	
	return 0;
}
