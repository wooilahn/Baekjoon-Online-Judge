#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);

  vector<int> v;
  v.push_back(A);
  v.push_back(B);
  v.push_back(C);
  sort(v.begin(), v.end());

  char str[10] = {0};
  scanf("%s", str);

  for(int i=0; i<strlen(str); i++){
    if(str[i] == 'A')
	  printf("%d", v[0]);
	else if (str[i] == 'B')
		printf("%d", v[1]);
	else if (str[i] == 'C')
		printf("%d", v[2]);
	printf(" ");
  }
  printf("\n");

  return 0;
}
