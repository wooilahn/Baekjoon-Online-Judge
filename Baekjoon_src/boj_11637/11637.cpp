#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int n;
	scanf("%d", &n);
	vector<int> v;
	v.resize(n+2);

	int num;
	int sum=0, max_vote=0, max_idx=-1, max_n = 0;
	for(int i=1; i<=n; i++){
	  scanf("%d", &num);
	  v[i] = num;
	  sum += num;
	 
	  if(max_vote < num){
	    max_vote = num;
		max_idx = i;
	    max_n = 1;
	  }
	  else if(max_vote == num)
	    max_n++;
	}

	if(max_n > 1){
	  printf("no winner\n");
	}
	else if(max_n == 1){
	  if(sum/2 < max_vote)
	    printf("majority winner %d\n", max_idx);
	  else
	    printf("minority winner %d\n", max_idx);
	}
  }

  return 0;
}
