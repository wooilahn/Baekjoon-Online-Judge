#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

using namespace std;

bool arr[1500003] = {0};

void eratos(){
  arr[0] = 1;
  arr[1] = 1;

  for(int i=2; i<=750000; i++){
    if(arr[i])
	  continue;

	for(int k=i+i; k<=1500000; k+=i)
	  arr[k] = 1;
  }

  return;
}

int check_p(int num){
  int ans = 0;
  string s;

  for(int i=num; i<=1500000; i++){
    if(arr[i])
	  continue;

	s = to_string(i);
	bool p_flag = true;

	for(int k=0; k<s.size()/2; k++){
	  if(s[k] != s[s.size()-1-k]){
	    p_flag = false;
		break;
	  }
	}

	if(p_flag){
	  ans = i;
	  break;
	}
  }

  return ans;
}

int main(){
  int N;
  scanf("%d", &N);
  eratos();
  printf("%d\n", check_p(N));

  return 0;
}
