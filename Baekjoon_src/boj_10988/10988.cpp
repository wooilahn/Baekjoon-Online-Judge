#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

char str[105] = {0};

int main(){
  bool p_flag = true;
  scanf("%s", str);

  int len = strlen(str);

  for(int i=0; i<len/2; i++){
    if(str[i] != str[len-1-i]){
	  p_flag = false;
	  break;
	}
  }

  if(p_flag)
    printf("1\n");
  else if(!p_flag)
    printf("0\n");

  return 0;
}
