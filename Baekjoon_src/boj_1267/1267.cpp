#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N, num;
  scanf("%d", &N);

  int ySum = 0;
  int mSum = 0;

  for(int i=0; i<N; i++){
    scanf("%d", &num);

	ySum += ((num / 30) + 1) * 10;
	mSum += ((num / 60) + 1) * 15;
  }

  if(ySum < mSum)
    printf("Y %d\n", ySum);
  else if(ySum > mSum)
    printf("M %d\n", mSum);
  else if(ySum == mSum)
	printf("Y M %d\n", ySum);

  return 0;
}
