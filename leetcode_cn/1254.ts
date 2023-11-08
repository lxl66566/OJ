function closedIsland(grid: number[][]): number {
  let flag = true,
    ans = 0;

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; ++j) {
      if (grid[i][j] === 0) {
        flag = true;
        dfs(i, j);
        if (flag) ++ans;
      }
    }
  }
  function dfs(x: number, y: number) {
    if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
      flag = false;
      return;
    }
    if (grid[x][y] !== 0) {
      return;
    }
    grid[x][y] = 2;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
  }
  return ans;
}

const grid = [
  [0, 0, 1, 0, 0],
  [0, 1, 0, 1, 0],
  [0, 1, 1, 1, 0],
];

console.log(closedIsland(grid));
