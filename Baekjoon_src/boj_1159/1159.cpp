#include <iostream>
#include <string>

using namespace std;
int check[26] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  string s;

  while(N--){
    cin >> s;
	check[s[0]-'a']++;
  }

  int n_five = 0;
  for(int i=0; i<26; i++){
    if(check[i] >= 5){
	  cout << (char)('a'+i);
	  n_five++;
	}
  }

  if(n_five == 0)
    cout << "PREDAJA";
  cout << endl;

  return 0;
}
