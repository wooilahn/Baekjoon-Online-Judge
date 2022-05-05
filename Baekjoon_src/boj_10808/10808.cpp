#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int arr[30] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  
  for(int i=0; i<s.size(); i++){
    arr[s[i]-'a']++;
  }

  for(char c='a'; c<='z'; c++){
    cout << (int)arr[c-'a'] << " ";
  }
  cout << endl;

  return 0;
}
