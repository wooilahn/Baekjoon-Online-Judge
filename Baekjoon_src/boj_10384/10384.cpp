#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int char_cnt[30] = {0};

int main(){
  int n;
  cin >> n;

  string s;
  getline(cin, s);

  for(int i=1; i<=n; i++){
    memset(char_cnt, 0, sizeof(char_cnt));
    getline(cin, s);
	
	for(int k=0; k<s.size(); k++){
	  s[k] = tolower(s[k]);
	  if(s[k] >= 'a' && s[k] <= 'z')
	    char_cnt[int(s[k]-'a')]++;
	}
	
	int single_cnt = 0;
	int double_cnt = 0;
	int triple_cnt = 0;

	for(char c='a'; c<='z'; c++){
	  if(char_cnt[int(c - 'a')] >= 1)
	    single_cnt++;
	  if(char_cnt[int(c - 'a')] >= 2)
	    double_cnt++;
	  if(char_cnt[int(c - 'a')] >= 3)
	    triple_cnt++;
	}

	cout << "Case " << i << ": ";
	if(triple_cnt == 26)
	  cout << "Triple pangram!!!\n";
	else if(double_cnt == 26)
	  cout << "Double pangram!!\n";
	else if(single_cnt == 26)
	  cout << "Pangram!\n";
	else
	  cout << "Not a pangram\n";
  }

  return 0;
}
