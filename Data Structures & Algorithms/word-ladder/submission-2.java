class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (beginWord.equals(endWord)) {
            return 0;
        }

        wordList = new ArrayList<>(wordList);
        wordList.add(beginWord);

        Map<String, List<String>> adj = new HashMap<>();

        int n = wordList.size();
        int w = endWord.length();

        for (int i = 0; i < n; i++) {
            String word1 = wordList.get(i);

            for (int j = i + 1; j < n; j++) {
                String word2 = wordList.get(j);

                int mismatches = 0;

                for (int k = 0; k < w; k++) {
                    if (word1.charAt(k) != word2.charAt(k)) {
                        mismatches++;
                    }
                }

                if (mismatches == 1) {
                    adj.computeIfAbsent(word1, key -> new ArrayList<>()).add(word2);
                    adj.computeIfAbsent(word2, key -> new ArrayList<>()).add(word1);
                }
            }
        }

        Set<String> visited = new HashSet<>();
        Queue<String> bfs = new ArrayDeque<>();

        visited.add(beginWord);
        bfs.offer(beginWord);

        int steps = 1;

        while (!bfs.isEmpty()) {
            int size = bfs.size();

            for (int i = 0; i < size; i++) {
                String currentWord = bfs.poll();

                for (String nextWord : adj.getOrDefault(currentWord, Collections.emptyList())) {
                    if (nextWord.equals(endWord)) {
                        return steps + 1;
                    }

                    if (visited.add(nextWord)) {
                        bfs.offer(nextWord);
                    }
                }
            }

            steps++;
        }

        return 0;
    }
}