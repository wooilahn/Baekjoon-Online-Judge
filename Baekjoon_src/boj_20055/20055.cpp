#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>

using namespace std;

int N, K;

deque<int> duration;
deque<bool> conveyor;

void rotate_conveyor(){
  duration.push_front(duration.back());
  duration.pop_back();

  conveyor.push_front(conveyor.back());
  conveyor.pop_back();

  conveyor[N-1] = false;
  return;
}

void move_robot(){
  for(int i=N-2; i>=0; i--){
    if(conveyor[i] && !conveyor[i+1] && duration[i+1] > 0){
	  conveyor[i] = false;
	  conveyor[i+1] = true;
	  duration[i+1]--;
	}
  }

  conveyor[N-1] = false;
  return;
}

void put_robot(){
  if(conveyor[0] == false && duration[0] > 0){
    conveyor[0] = true;
	duration[0]--;
  }

  return;
}

int check_duration(){
  int zero_n = 0;

  for(int i=0; i<duration.size(); i++){
    if(duration[i] == 0)
	  zero_n++;
  }

  return zero_n;
}

int main(){
  scanf("%d %d", &N, &K);

  int d;
  for(int i=0; i<2*N; i++){
    scanf("%d", &d);
	duration.push_back(d);
	conveyor.push_back(false);
  }

  int stage = 0;
  while(true){
    stage++;
    rotate_conveyor();
	move_robot();
	put_robot();

	if(check_duration() >= K){
	  printf("%d\n", stage);
	  return 0;
	}
  }

  return 0;
}
