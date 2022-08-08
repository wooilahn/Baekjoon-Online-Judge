#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  ans.resize(N+5);

  for(int i=1; i<=N; i++)
    ans[i] = i;

  for(int i=0; i<M; i++){
    int a, b;
	cin >> a >> b;
	int tmp = ans[a];
	ans[a] = ans[b];
	ans[b] = tmp;
  }

  for(int i=1; i<=N; i++)
    cout << ans[i] << " ";
  cout << '\n';
  return 0;
}
