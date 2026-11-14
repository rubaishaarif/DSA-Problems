 #include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class WordSearch {
    vector<vector<char>> board;
    vector<vector<bool>> visited;   
    vector<pair<int, int>> path;    
    string word;
    int rows, cols;
 
    // The four allowed moves
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    bool dfs(int r, int c, int index) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) 
			return false;
        if (visited[r][c]) 
			return false;
        if (board[r][c] != word[index]) 
			return false;
        visited[r][c] = true;
        path.push_back({r, c});
        if (index == (int)word.size() - 1) 
			return true;
        for (int d = 0; d < 4; d++) {
            if (dfs(r + dr[d], c + dc[d], index + 1))
				return true;
        }
        visited[r][c] = false;
        path.pop_back();
        return false;
    }
 
public:
    WordSearch(vector<vector<char>>& b, string& w) {
        board = b;
        word = w;
        rows = board.size();
        cols = board.empty() ? 0 : board[0].size();
        visited.assign(rows, vector<bool>(cols, false));
    }
 
    bool exist() {
        if (word.empty()) 
			return true;
        if ((int)word.size() > rows * cols) 
			return false;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0)) 
				return true;
            }
        }
        return false;
    }
 
    void printPath()  {
        for (size_t i = 0; i < path.size(); i++) {
            cout << word[i] << "(" << path[i].first << "," << path[i].second << ")";
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << "\n";
    }
};
 
int main() {
    int m, n;
 	cout<<"input m and n\n";
 	cin >> m >> n;
 	cout<<m<<","<<n<<"\n";
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
 
    string word;
    cin >> word;
 
    WordSearch solver(board, word);
    bool found = solver.exist();
 
    cout << (found ? "true" : "false") << "\n";
    if (found) {
        cout << "Path: ";
        solver.printPath();
    }
    return 0;
}
 
