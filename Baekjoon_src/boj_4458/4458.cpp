#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
char str[50] = {0};

int main(){

  int N;
  scanf("%d\n", &N);

  while(N--){
      fgets(str, 40, stdin);
	  if (islower(str[0]))
		  str[0] = char(str[0] - 'a' + 'A');
	  printf("%s", str);
  }
  
  return 0;
}
