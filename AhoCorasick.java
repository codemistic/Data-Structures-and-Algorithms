import java.util.*;

public class AhoCorasick {

    // Trie Node Class
    static class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>();
        TrieNode failureLink = null;
        List<String> output = new ArrayList<>();
    }

    private TrieNode root = new TrieNode();

    // Step 1: Build the Trie
    public void addKeyword(String keyword) {
        TrieNode currentNode = root;
        for (char c : keyword.toCharArray()) {
            currentNode = currentNode.children.computeIfAbsent(c, k -> new TrieNode());
        }
        currentNode.output.add(keyword);
    }

    // Step 2: Build Failure Links
    public void buildFailureLinks() {
        Queue<TrieNode> queue = new LinkedList<>();
        root.failureLink = root;
        queue.add(root);

        while (!queue.isEmpty()) {
            TrieNode current = queue.poll();

            for (Map.Entry<Character, TrieNode> entry : current.children.entrySet()) {
                char c = entry.getKey();
                TrieNode child = entry.getValue();

                // Set failure link
                TrieNode failure = current.failureLink;
                while (failure != root && !failure.children.containsKey(c)) {
                    failure = failure.failureLink;
                }

                if (failure.children.containsKey(c) && failure.children.get(c) != child) {
                    child.failureLink = failure.children.get(c);
                } else {
                    child.failureLink = root;
                }

                // Merge output from failure link
                child.output.addAll(child.failureLink.output);
                queue.add(child);
            }
        }
    }

    // Step 3: Search the Text
    public List<String> search(String text) {
        List<String> results = new ArrayList<>();
        TrieNode currentNode = root;

        for (char c : text.toCharArray()) {
            while (currentNode != root && !currentNode.children.containsKey(c)) {
                currentNode = currentNode.failureLink;
            }
            if (currentNode.children.containsKey(c)) {
                currentNode = currentNode.children.get(c);
            }

            // Add matches to results
            results.addAll(currentNode.output);
        }

        return results;
    }

    public static void main(String[] args) {
        AhoCorasick ac = new AhoCorasick();
        ac.addKeyword("he");
        ac.addKeyword("she");
        ac.addKeyword("hers");
        ac.addKeyword("his");
        
        ac.buildFailureLinks();
        
        List<String> matches = ac.search("ushers");
        System.out.println("Matches found: " + matches);
    }
}
