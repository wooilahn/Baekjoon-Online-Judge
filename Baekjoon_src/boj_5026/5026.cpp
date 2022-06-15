#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
 ios::sync_with_stdio(false);
 cin.tie(0);

 int N;
 cin >> N;

 while(N--){
   string s;
   cin >> s;

   if(s.find('+') != -1){
     int num1 = atoi(s.substr(0, s.find('+')).c_str());
	 int num2 = atoi(s.substr(s.find('+') + 1, s.size()).c_str());
	 cout << num1 + num2 << endl;
   }
   else if(s.find('=') != -1){
     cout << "skipped\n";
   }
 }



 return 0;
}
