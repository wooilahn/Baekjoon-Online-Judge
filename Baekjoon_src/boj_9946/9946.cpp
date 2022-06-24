#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int check1[26] = {0};
int check2[26] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s1, s2;
  int test_case = 1;

  while(true){
    memset(check1, 0, sizeof(check1));
	memset(check2, 0, sizeof(check2));
    cin >> s1 >> s2;

	if(s1 == "END" && s2 == "END")
	  break;

	for(int i=0; i<s1.size(); i++)
	  check1[s1[i]-'a']++;

	for(int i=0; i<s2.size(); i++)
	  check2[s2[i]-'a']++;

	bool flag = false;

	for(int i=0; i<26; i++){
	  if(check1[i] != check2[i]){
	    flag = true;
		break;
	  }
	}

	cout << "Case " << test_case << ": ";
	test_case++;

	if(flag)
	  cout << "different" << endl;
	else
	  cout << "same" << endl;
  }

  return 0;
}
