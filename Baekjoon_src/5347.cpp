#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int gcd(int a, int b){
  int n1 = a;
  int n2 = b;

  while(n2 != 0){
    int tmp = n1 % n2;
	n1 = n2;
	n2 = tmp;
  }

  return n1;
}

int main(){
  int T;
  scanf("%d", &T);

  int a, b;

  while(T--){
    scanf("%d %d", &a, &b);
	int g = gcd(a, b);
	printf("%d\n", g*(a/g)*(b/g));
  }

  return 0;
}
