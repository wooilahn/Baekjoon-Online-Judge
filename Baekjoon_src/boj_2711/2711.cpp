#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
  int T, n;
  string s;

  scanf("%d", &T);

  while(T--){
    cin >> n >> s;
    s.erase(s.begin()+n-1);
    cout << s << endl;
  }

  return 0;
}
