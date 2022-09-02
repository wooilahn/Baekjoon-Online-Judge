#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 0:(R)ed, 1:(B)lue, 2:(Y)ellow, 3:(G)reen
int v[4][10] = {0};
int st[10] = {0};


int r_cnt = 0;
int b_cnt = 0;
int y_cnt = 0;
int g_cnt = 0;
int max_n = 0;

int main(){
  char c;
  int n;

  for(int i=0; i<5; i++){
    scanf("%c %d", &c, &n);
	getchar();

	max_n = max(n, max_n);
	
	if(c == 'R'){
	  v[0][n]++;
	  st[n]++;
	  r_cnt++;
	}
	else if(c == 'B'){
	  v[1][n]++;
	  st[n]++;
	  b_cnt++;
	}
	else if(c == 'Y'){
	  v[2][n]++;
	  st[n]++;
	  y_cnt++;
	}
	else if(c == 'G'){
	  v[3][n]++;
	  st[n]++;
	  g_cnt++;
	}
  }

  int ans = 0;
  int st_n = 0;
  int dup_cnt = 0;
  int dup_n = 0;
  int tmp_n = 0;

  for(int i=0; i<10; i++){
    if(st[i])
	  tmp_n++;
	else if(!st[i])
	  tmp_n = 0;

	if(dup_cnt < st[i]){
	  dup_cnt = st[i];
	  dup_n = i;
	}

	st_n = max(tmp_n, st_n);
  }

  if(r_cnt == 5 || b_cnt == 5 || y_cnt == 5 || g_cnt == 5){
    // rule 4
    ans = max(ans, 600+max_n);

	// rule 1
	if(st_n == 5)
	  ans = max(ans, 900+max_n);
  }

  // rule 2
  if(dup_cnt == 4)
    ans = max(ans, 800+dup_n);
 
  // rule 3
  if(dup_cnt == 3){
    int second_dup_cnt = 0;
	int second_dup_n = 0;

	for(int k=0; k<10; k++){
	  if(k == dup_n)
	    continue;

	  if(second_dup_cnt < st[k]){ 
	    second_dup_cnt = st[k];
		second_dup_n = k;
	  }
	}

	if(second_dup_cnt == 2)
		ans = max(ans, 700+dup_n*10+second_dup_n);
  }

  // rule 5
  if(st_n == 5)
    ans = max(ans, 500+max_n);

  // rule 6
  if(dup_cnt == 3)
    ans = max(ans, 400+dup_n);

  // rule 7
  if(dup_cnt == 2){
	  // rule 8
	  ans = max(ans, 200+dup_n);

	  int second_dup_cnt = 0;
	  int second_dup_n = 0;

	  for (int k = 0; k < 10; k++) {
		  if (k == dup_n)
			  continue;

		  if (second_dup_cnt < st[k]) {
			  second_dup_cnt = st[k];
			  second_dup_n = k;
		  }
	  }

	  if(second_dup_cnt == 2)
		ans = max(ans, 300+max(dup_n, second_dup_n)*10+min(dup_n, second_dup_n));
  }

  ans = max(ans, 100+max_n);

  printf("%d\n", ans);

  return 0;
}
