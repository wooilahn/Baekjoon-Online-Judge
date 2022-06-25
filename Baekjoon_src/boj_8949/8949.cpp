#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s1,s2;
  cin >> s1 >> s2;

  queue<char> q1, q2;
  stack<string> ans;

  for(int i=s1.size()-1; i>=0; i--)
    q1.push(s1[i]);
  for(int i=s2.size()-1; i>=0; i--)
    q2.push(s2[i]);

  int num1, num2;
  while(true){
    num1 = 0;
	num2 = 0;

	if(q1.empty() && q2.empty())
	  break;

	if(!q1.empty()){
	  num1 = int(q1.front() - '0');
	  q1.pop();
	}
	if(!q2.empty()){
	  num2 = int(q2.front() - '0');
	  q2.pop();
	}

	int tmp = num1 + num2;
	ans.push(to_string(tmp));
  }

  while(!ans.empty()){
    cout << ans.top();
	ans.pop();
  }
  cout << endl;

  return 0;
}
