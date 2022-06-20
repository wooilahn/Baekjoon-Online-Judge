#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  string s;
  getline(cin, s);
  bool check[26] = {0};

  for(int i=0; i<N; i++){
    memset(check, 0, sizeof(check));
    getline(cin, s);

	for(int k=0; k<s.size(); k++){
	  if(islower(s[k]))
	    check[s[k]-'a'] = true;
	  else if(isupper(s[k])){
	    s[k] = tolower(s[k]);
		check[s[k]-'a'] = true;
	  }
	}

	int cnt = 0;
	string ans;

	for(char c = 'a'; c<='z'; c++){
	  if(check[c-'a'])
	    cnt++;
	  else
	    ans.push_back(c);
	}

	if(cnt == 26)
	  cout << "pangram" << endl;
	else {
	  cout << "missing ";

	  for(int k=0; k<ans.size(); k++)
	    cout << ans[k];
	  cout << endl;
	}
  }

  return 0;
}

