#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){
  // @: *3
  // %: +5
  // #: -7

  int t;
  scanf("%d\n", &t);

  while(t--){
    char str[50] = {0};
	fgets(str, 45, stdin);

	char* res;
	double target;
	int cnt = 1;
	res = strtok(str, " ");

	while(res != NULL){
		if(cnt == 1){
		  target = atof(res);
		}
		else{
		  if(res[0] == '@')
		    target *= 3.0;
		  else if(res[0] == '%')
		    target += 5.0;
		  else if(res[0] == '#')
		    target -= 7.0;
		}

		res = strtok(NULL, " ");
		cnt++;
	}

	printf("%.2lf\n", target);
  }

  return 0;
}
