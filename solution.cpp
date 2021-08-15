//
// Created by Kylian Lee on 2021/08/15.
//


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v1;
vector<vector<long long>> v2;
vector<vector<bool>> visited;
int row, column;

long long solution(int x, int y);

int main(){
  cin >> row >> column;
  v1.resize(row);
  v2.resize(row);
  visited.resize(row);
  for (int i = 0; i < row; ++i){
    v1[i].resize(column);
    v2[i].resize(column, 0);
    visited[i].resize(column, false);
  }
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      cin >> v1[i][j];
    }
  }
  v2[0][0] = 1;
  cout << solution(row - 1, column - 1) << endl;
  //  for (int i = 0; i < row; ++i) {
  //    for (int j = 0; j < column; ++j) {
  //      cout << v2[i][j] << ' ';
  //    }
  //    cout << endl;
  //}
  return 0;
}

long long solution(int x, int y){
  if(visited[x][y])
    return v2[x][y];
  if(x < row - 1 && v1[x][y] < v1[x + 1][y]){
    v2[x][y] += solution(x + 1, y);
  }
  if(x > 0 && v1[x][y] < v1[x - 1][y]){
    v2[x][y] += solution(x - 1, y);
  }
  if(y > 0 && v1[x][y] < v1[x][y - 1]){
    v2[x][y] += solution(x, y - 1);
  }
  if(y < column - 1 && v1[x][y] < v1[x][y +1]){
    v2[x][y] += solution(x, y + 1);
  }
  visited[x][y] = true;
  return v2[x][y];
}