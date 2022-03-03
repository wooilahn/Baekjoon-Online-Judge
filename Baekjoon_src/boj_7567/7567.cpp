#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

char str[55] = {0};

int main(){
  scanf("%s", str);
  int ans = 10;

  for(int i=1; i<strlen(str); i++){
    char target = str[i];

	if(str[i-1] == str[i])
	  ans += 5;
	else if(str[i-1] != str[i])
	  ans += 10;
  }

  printf("%d\n", ans);
  return 0;
}
