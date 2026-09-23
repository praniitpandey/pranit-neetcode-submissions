class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (beginWord.equals(endWord))
            return 0;

        wordList = new ArrayList<>(wordList);
        Map<String, List<String>> adj = new HashMap<>();
        wordList.add(beginWord);

        int n = wordList.size(), w = endWord.length();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mismatches = 0;

                for (int k = 0; k < w; k++) {
                    if (wordList.get(i).charAt(k) != wordList.get(j).charAt(k))
                        ++mismatches;
                }

                if (mismatches == 1) {
                    if (!adj.containsKey(wordList.get(i)))
                        adj.put(wordList.get(i), new ArrayList<String>());
                    adj.get(wordList.get(i)).add(wordList.get(j));

                    if (!adj.containsKey(wordList.get(j)))
                        adj.put(wordList.get(j), new ArrayList<String>());
                    adj.get(wordList.get(j)).add(wordList.get(i));
                }
            }
        }

        Set<String> visited = new HashSet<>();
        Queue<String> bfs = new ArrayDeque<>();

        visited.add(beginWord);
        bfs.add(beginWord);
        int steps = 1;

        while (!bfs.isEmpty()) {
            int size = bfs.size();

            for (int i = 0; i < size; i++) {
                String currentWord = bfs.poll();

                for (String nextWord : adj.getOrDefault(currentWord, Collections.emptyList())) {
                    if (nextWord.equals(endWord)) {
                        return steps + 1;
                    }

                    else if (!visited.contains(nextWord)) {
                        visited.add(nextWord);
                        bfs.add(nextWord);
                    }
                }
            }

            ++steps;
        }

        return 0;
    }
}
