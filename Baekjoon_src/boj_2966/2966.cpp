#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  
  string s;
  cin >> s;

  int s_ans=0, c_ans=0, h_ans=0;
  char s_cho[3] = {'A', 'B', 'C'};
  char c_cho[4] = {'B', 'A', 'B', 'C'};
  char h_cho[6] = {'C', 'C', 'A', 'A', 'B', 'B'};

  for(int i=0; i<s.size(); i++){
    if(s[i] == s_cho[i%3])
	  s_ans++;
	if(s[i] == c_cho[i%4])
	  c_ans++;
	if(s[i] == h_cho[i%6])
	  h_ans++;
  }

  int max_ans = max(s_ans, max(c_ans, h_ans));
  cout << max_ans << '\n';

  if(max_ans == s_ans)
    cout << "Adrian" << '\n';
  if(max_ans == c_ans)
    cout << "Bruno" << '\n';
  if(max_ans == h_ans)
    cout << "Goran" << '\n';

  return 0;
}
