#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
int N, K;

void print_raw(){
  for(int i=0; i<N; i++)
    cout << v[i] << endl;
  return;
}

void print_reverse_left_right(){
  for(int i=0; i<N; i++){
    reverse(v[i].begin(), v[i].end());
	cout << v[i] << endl;
  }
  return;
}

void print_reverse_up_down(){
  for(int i=N-1; i>=0; i--){
    cout << v[i] << endl;
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  string s;
  for(int i=0; i<N; i++){
    cin >> s;
	v.push_back(s);
  }

  cin >> K;

  switch(K){
    case 1:
	print_raw();
	break;
	case 2:
	print_reverse_left_right();
	break;
	case 3:
	print_reverse_up_down();
	break;
	default: 
	break;
  }

  return 0;
}
