#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for(int idx=1; idx<=n; idx++){
    string s;
	cin >> s;

	for(int i=0; i<s.size(); i++){
	 if(s[i] == 'Z')
	   s[i] = 'A';
	 else
	   s[i] = char(s[i]+1);
	}

	cout << "String #" << idx << '\n';
	cout << s << "\n\n";
  }

  return 0;
}
