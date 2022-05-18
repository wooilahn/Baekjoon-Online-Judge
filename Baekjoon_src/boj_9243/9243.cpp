#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  string s1, s2;
  cin >> s1;
  cin >> s2;

  bool del_flag = true;

  if(N%2==1){
    for(int i=0; i<s1.size(); i++){
	  if(s1[i] == s2[i]){
	    del_flag = false;
		break;
	  }
	}
  }
  else if(N%2==0){
    for(int i=0; i<s1.size(); i++){
	  if(s1[i] != s2[i]){
	    del_flag = false;
		break;
	  }
	}
  }

  if(del_flag)
    cout << "Deletion succeeded" << endl;
  else
    cout << "Deletion failed" << endl;


  return 0;
}

