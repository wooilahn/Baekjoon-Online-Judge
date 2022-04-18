#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;
int arr[5];

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int min_v = 99;
	int max_v = -1;
	int num, sum = 0;

	for(int i=0; i<5; i++)
	  scanf("%d", &arr[i]);

	sort(arr, arr+5);

	if(arr[3] - arr[1] >= 4)
	  printf("KIN\n");
	else
	  printf("%d\n", arr[1] + arr[2] + arr[3]);
  }

  return 0;
}
