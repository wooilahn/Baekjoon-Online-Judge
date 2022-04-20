#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int arr[503] = {0};

int main(){
  int K, P, M;
  scanf("%d", &K);
  
  while(K--){
    scanf("%d %d", &P, &M);
	memset(arr, 0, sizeof(arr));

	int num, ans = 0;
	for(int i=0; i<P; i++){
	  scanf("%d", &num);

	  if(!arr[num])
		arr[num] = 1;
	  else
	    ans++;
	}

	printf("%d\n", ans);
  }

  return 0;
}
