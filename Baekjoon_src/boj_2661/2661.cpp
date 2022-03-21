#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int N;
string result = "";
bool finish_flag = false;

void solve(string cur_str, int cnt){

  if(finish_flag)
    return;

  int len = cur_str.size();

  for(int i=1; i<= len/2; i++){
    if(cur_str.substr(len-i, i) == cur_str.substr(len-2*i, i))
	  return;
  }

  if(cnt == N){
    result = cur_str;
	finish_flag = true;
	return;
  }

  solve(cur_str + "1", cnt+1);
  solve(cur_str + "2", cnt+1);
  solve(cur_str + "3", cnt+1);

  return;
}

int main(){
  scanf("%d", &N);
  solve("", 0);
  cout << result;

  return 0;
}
