#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char strA[105] = {0};
char strB[105] = {0};
char str_ans[300] = {0};

int main(){
  long long A, B;
  char c;

  scanf("%s\n%c\n%s", strA, &c, strB);

  int lenA = strlen(strA); // 10^0=1, 10^1=2, 10^2=3, 10^(n) = n-1의 길이
  int lenB = strlen(strB); // 100*1000 = 10^2(3) * 10^3(4) = 10^5 = 100000 (6)

  if(c =='+'){
    if(lenA > lenB){
      strcpy(str_ans, strA);
      str_ans[lenA-lenB] = '1';
    }
    else if(lenA < lenB){
      strcpy(str_ans, strB);
      str_ans[lenB-lenA] = '1';
    }
    else if(lenA == lenB){
      strcpy(str_ans, strA);
      str_ans[0] = '2';
    }
  }
  else if(c=='*'){
    int ans_len = max(0, lenA-1) + max(0, lenB-1) + 1;

    for(int i=0; i<ans_len; i++){
      if(i == 0)
        str_ans[i] = '1';
      else
        str_ans[i] = '0';
    }
    str_ans[ans_len] = '\0';
  }
  
  printf("%s\n", str_ans);

  return 0;
}
