#include <iostream>

using namespace std;

int main(){

  int ans_r, ans_c;
  int ans_v = -1;
  int num;

  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++){
	  scanf("%d", &num);
	  if(ans_v < num){
	    ans_v = num;
		ans_r = i;
		ans_c = j;
	  }
	}
  }

  printf("%d\n%d %d\n", ans_v, ans_r, ans_c);

  return 0;
}
