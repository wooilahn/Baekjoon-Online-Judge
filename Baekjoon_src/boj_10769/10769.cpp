#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  getline(cin, s);

  int sad_face = 0;
  int happy_face = 0;

  for(int i=0; i<s.size(); i++){
    if(s[i] == ':'){
	  int h_value = s.substr(i, 3).find(":-)");
	  int s_value = s.substr(i, 3).find(":-(");

	  if(h_value >= 0)
	    happy_face++;
	  else if(s_value >= 0)
	    sad_face++;
	}
  }

  if(sad_face == 0 && happy_face == 0)
    printf("none\n");
  else if(sad_face == happy_face)
    printf("unsure\n");
  else if(happy_face > sad_face)
    printf("happy\n");
  else if(happy_face < sad_face)
    printf("sad\n");

  return 0;
}
 
