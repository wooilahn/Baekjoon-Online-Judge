#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> channel;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  int cur_channel = 0;
  int kbs1_idx = 0;
  int kbs2_idx = 0;

  string s;
  for(int i=0; i<N; i++){
    cin >> s;

	if(s.compare("KBS1") == 0)
	  kbs1_idx = i;
	if(s.compare("KBS2") == 0)
	  kbs2_idx = i;

	channel.push_back(s);
  }

  for(int i=0; i<kbs1_idx; i++)
    cout << "1";
  for(int i=0; i<kbs1_idx; i++)
    cout << "4";
  
  if(kbs1_idx > kbs2_idx)
    kbs2_idx++;

  for(int i=0; i<kbs2_idx; i++)
    cout << "1";
  for(int i=0; i<kbs2_idx-1; i++)
    cout << "4";

  cout << "\n";


  return 0;
}
