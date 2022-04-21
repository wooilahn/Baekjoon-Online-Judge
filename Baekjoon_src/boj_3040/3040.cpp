#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
vector<int> p_v;

int main(){
  
  int num;
  for(int i=0; i<9; i++){
    scanf("%d", &num);
	v.push_back(num);
  }

  p_v.resize(9);
  for(int i=0; i<7; i++){
    p_v.at(p_v.size()-1-i) = 1;
  }

  do {
    int sum = 0;
    for(int i=0; i<9; i++){
	  if(p_v[i])
	    sum += v[i];
	}

	if(sum == 100){
	  for(int i=0; i<9; i++){
	    if(p_v[i])
		  printf("%d\n", v[i]);
	  }
	}
  } while(next_permutation(p_v.begin(), p_v.end()));


  return 0;
}
