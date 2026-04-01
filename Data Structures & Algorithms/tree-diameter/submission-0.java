class Solution {
    private List<Set<Integer>> adj;

    public int treeDiameter(int[][] edges) {
        int n = edges.length + 1;
        adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(new HashSet<Integer>());
        }

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        
        int farthestNode = dfs(0, -1)[0];
        int farthestDistance = dfs(farthestNode, -1)[1];

        return farthestDistance;
    }

    private int[] dfs(int node, int parent) {
        int farthestDistance = 0, farthestNode = node;

        for (int neighbor : adj.get(node)) {
            if (neighbor == parent) {
                continue;
            }
            int[] currentFarthest = dfs(neighbor, node);

            if (currentFarthest[1] + 1 > farthestDistance) {
                farthestNode = currentFarthest[0];
                farthestDistance = currentFarthest[1] + 1;
            }
        }

        return new int[]{farthestNode, farthestDistance};
    }
}