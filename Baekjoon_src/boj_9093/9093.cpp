#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
 ios::sync_with_stdio(false);
 cin.tie(0);

 int T;
 cin >> T;

 string s;
 getline(cin, s);

 while(T--){
   getline(cin, s);
   stringstream sstream(s);
   vector<string> s_v;
   string token;

   while(getline(sstream, token, ' ')){
     s_v.push_back(token);
   }

   for(int i=0; i<s_v.size(); i++){
     reverse(s_v[i].begin(), s_v[i].end());
     cout << s_v[i];

	 if(i != s_v.size()-1)
	   cout << ' ';
   }
   cout << endl;
 }

 return 0;
}
