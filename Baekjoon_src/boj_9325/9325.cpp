#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  int s, q, p, n;

  while(T--){
    int total_price = 0;

	scanf("%d", &s);
	scanf("%d", &n);
	while(n--){
	  scanf("%d %d", &q, &p);
	  total_price += q*p;
	}
	
	total_price += s;
	printf("%d\n", total_price);
  }

  return 0;
}
