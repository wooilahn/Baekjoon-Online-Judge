#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> s_v1;
vector<string> s_v2;

bool comp1(string s1, string s2){
  if(s1.size() == s2.size()){
    return s1 > s2;
  }
  else
    return s1.size() > s2.size();
}

bool comp2(string s1, string s2){
  return s1+s2 > s2+s1;
}

int main(){
  int N, K;
  scanf("%d %d", &K, &N);

  string s;
  for(int i=0; i<K; i++){
    cin >> s;
	s_v1.push_back(s);
	s_v2.push_back(s);
  }

  sort(s_v1.begin(), s_v1.end(), comp1);

  for(int i=0; i<N-K; i++)
    s_v2.push_back(s_v1[0]);

  sort(s_v2.begin(), s_v2.end(), comp2);

  for(int i=0; i<s_v2.size(); i++)
    cout << s_v2[i];
  cout << endl;

  return 0;
}
