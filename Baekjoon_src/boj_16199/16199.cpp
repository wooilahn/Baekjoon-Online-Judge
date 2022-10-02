#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int by, bm, bd;
  int cy, cm, cd;

  scanf("%d %d %d", &by, &bm, &bd);
  scanf("%d %d %d", &cy, &cm, &cd);

  int age_man = cy-by;

  if(bm > cm)
    age_man--;
  else if(bm == cm){
    if(bd > cd)
	  age_man--;
  }

  int age_se = cy-by + 1;
  int age_yeon = cy-by; 

  printf("%d\n%d\n%d\n", age_man, age_se, age_yeon);

  return 0;
}
