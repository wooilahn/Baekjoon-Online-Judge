#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
 ios::sync_with_stdio(false);
 cin.tie(0);

 string s1, s2;

 cin >> s1;
 cin >> s2;

 if(s1.length() >= s2.length())
   cout << "go\n";
 else
   cout << "no\n";

 return 0;
}
