class Solution {
    long[][] dp;

    public long minimumTotalDistance(List<Integer> robots, int[][] factories) {
        Collections.sort(robots);
        Arrays.sort(factories, (a, b) -> a[0] - b[0]);

        dp = new long[robots.size()][factories.length];
        for (long[] row : dp) Arrays.fill(row, -1);

        return solve(robots, factories, 0, 0);
    }

    private long solve(List<Integer> robots, int[][] factories, int i, int j) {
        if (i == robots.size()) return 0;
        if (j == factories.length) return (long)1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long res = solve(robots, factories, i, j + 1); // skip factory

        long dist = 0;
        for (int k = 0; k < factories[j][1] && i + k < robots.size(); k++) {
            dist += Math.abs(robots.get(i + k) - factories[j][0]);
            res = Math.min(res, dist + solve(robots, factories, i + k + 1, j + 1));
        }

        return dp[i][j] = res;
    }
}