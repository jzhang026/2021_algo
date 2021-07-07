/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    let n = board.length; // 宽
    if (n == 0) return;
    let m = board[0].length; // 长

    // DFS标记所有能延续到边界的O
    // 能够联通到边界，说明不能被x包围
    function dfs(board, i, j) {
        // 检查DFS没有超出边界
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
            return;
        }
        // 标记能被边界触达的格子
        board[i][j] = 1;
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    // 上下，左右四条边界，分别对每个格子DFS查询
    for (let i = 0; i < n; i++) {
        dfs(board, i, 0);
        dfs(board, i, m - 1);
    }

    for (let i = 1; i< m - 1; i++) {
        dfs(board, 0, i)
        dfs(board, n - 1, i);
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
};


