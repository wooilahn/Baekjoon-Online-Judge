#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int P;
  cin >> P;

  while(P--){
    string s;
	cin >> s;

	int ans[9] = {0};

	for(int i=0; i<s.size(); i++){
	  string sub_s = s.substr(i, 3);

	  if(sub_s.size() == 3){
	    if(sub_s.compare("TTT") == 0)
		    ans[0]++;
		else if(sub_s.compare("TTH") == 0)
		    ans[1]++;
		else if (sub_s.compare("THT") == 0)
			ans[2]++;
		else if (sub_s.compare("THH") == 0)
			ans[3]++;
		else if (sub_s.compare("HTT") == 0)
			ans[4]++;
		else if (sub_s.compare("HTH") == 0)
			ans[5]++;
		else if (sub_s.compare("HHT") == 0)
			ans[6]++;
		else if (sub_s.compare("HHH") == 0)
			ans[7]++;
	  }
	}

	for(int i=0; i<8; i++)
	  cout << ans[i] << " ";
	cout << '\n';
  }

  return 0;
}
