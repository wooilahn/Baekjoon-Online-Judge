#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(){
  int total = 0;

  for(int i=0; i<10; i++){
    int num;
    scanf("%d", &num);
    v.push_back(num);
    total += num;
  }

  int freq_num = 0;
  int freq_cnt = 0;

  for(int i=0; i<10; i++){
    int cur_freq = count(v.begin(), v.end(), v[i]);

    if(freq_cnt < cur_freq){
      freq_cnt = cur_freq;
      freq_num = v[i];
    }
  }

  printf("%.0lf\n%d\n", (double)total/(double)10, freq_num);
  return 0;
}
