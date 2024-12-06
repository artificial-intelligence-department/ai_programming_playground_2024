#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;

  if (N < 1 || N > 9) {
    cerr << "Error: N must be between 1 and 9." << endl;
    return 1;
  }

  vector<vector<int>> arr(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;

    if (str.length() != N) {
      cerr << "Error: Each row must have exactly N characters." << endl;
      return 1;
    }

    for (int j = 0; j < N; j++) {
      arr[i][j] = str[j] - '0'; 

      if (arr[i][j] < 0 || arr[i][j] > 9) {
        cerr << "Error: Each cell must contain a digit between 0 and 9." << endl;
        return 1;
      }
    }
  }

  int Q;
  cin >> Q;

  if (Q < 1 || Q > 1000) {
    cerr << "Error: Q must be between 1 and 1000." << endl;
    return 1;
  }

  vector<pair<int, int>> queries(Q);

  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;

    if (x < 1 || x > N || y < 1 || y > N) {
      cerr << "Error: Query coordinates must be between 1 and N." << endl;
      return 1;
    }

    queries[i] = {x - 1, y - 1}; 
  }

  
  for (int i = 0; i < queries.size(); i++) {
    int x = queries[i].first; //
    int y = queries[i].second;

    if (arr[x][y] != 0) {
      cout << "1\n" << arr[x][y] << "\n";
      continue;
    }

    vector<bool> possible(N + 1, true);

    // Видалення чисел, які є в рядку x
    for (int j = 0; j < N; j++) {
      if (arr[x][j] != 0) {
        possible[arr[x][j]] = false;
      }
    }

    // Видалення чисел, які є в стовпці y
    for (int i = 0; i < N; i++) {
      if (arr[i][y] != 0) {
        possible[arr[i][y]] = false;
      }
    }

    vector<int> result;
    for (int i = 1; i <= N; i++) {
      if (possible[i]) {
        result.push_back(i);
      }
    }

    cout << result.size() << "\n";
    for (int num : result) {
      cout << num << " ";
    }
    cout << "\n";
  }

  return 0;
}
