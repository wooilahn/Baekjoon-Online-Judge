#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> answer;

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int n;
	answer.clear();
	scanf("%d", &n);
	int cnt = 0;

	for(int i=1; n>0; i*=10){
	  int remainder = n%2;
	  n /= 2;

	  if(remainder == 1)
	    answer.push_back(cnt);
	  cnt++;
	}

	for(int i=0; i<answer.size(); i++){
	  printf("%d ", answer[i]);
	}
	printf("\n");
  }

  return 0;
}
