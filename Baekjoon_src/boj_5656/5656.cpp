#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int main(){
  string s;
  int case_cnt = 1;
  
  while(true){
     getline(cin, s);
	 stringstream sstream(s);
	 string token;

	 string sign;
	 int a, b;
	 int cnt = 0;

	 while(getline(sstream, token, ' ')){
	   if(cnt == 0)
	     a = atoi(token.c_str());
	   else if(cnt == 1)
	     sign = token;
	   else if(cnt == 2)
	     b = atoi(token.c_str());
	     
	   cnt++;
	 }

	 bool comp_flag = false;

	 if(sign.compare("E") == 0)
	   break;
	 else if(sign.compare(">") == 0){
	   if(a > b)
	     comp_flag = true;
	   else
	     comp_flag = false;
	 }
	 else if(sign.compare(">=") == 0){
	   if(a >= b)
	     comp_flag = true;
	   else
	     comp_flag = false;
	 }
	 else if(sign.compare("<") == 0){
	   if(a < b)
	     comp_flag = true;
	   else
	     comp_flag = false;
	 }
	 else if(sign.compare("<=") == 0){
	   if(a <= b)
	     comp_flag = true;
	   else
	     comp_flag = false;
	 }
	 else if(sign.compare("==") == 0){
	   if(a == b)
	     comp_flag = true;
	   else
	     comp_flag = false;
	 }
	 else if(sign.compare("!=") == 0){
	   if(a != b)
	     comp_flag = true;
	   else
	     comp_flag = false;
	 }

	 cout << "Case " << case_cnt << ": ";
	 if(comp_flag)
	   cout << "true" << endl;
	 else
	   cout << "false" << endl;

	 case_cnt++;
  }

  return 0;
}

