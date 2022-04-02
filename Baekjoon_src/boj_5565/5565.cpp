#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int total;
  scanf("%d", &total);

  int price;
  for(int i=0; i<9; i++){
    scanf("%d", &price);
	total -= price;
  }

  printf("%d\n", total);
  return 0;
}
