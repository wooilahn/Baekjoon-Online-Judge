#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int in, out;
  int cur_n = 0;
  int ans = 0;

  for(int i=0; i<10; i++){
    scanf("%d %d", &out, &in);
	int tmp_n = cur_n;

	cur_n += in;
	cur_n -= out;

	ans = max(ans, max(tmp_n, cur_n));
  }

  printf("%d\n", ans);

  return 0;
}
