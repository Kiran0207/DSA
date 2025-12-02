class Solution {
public:
    string findOrder(vector<string>& words) {

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        // Mark present characters
        for (auto &w : words) {
            for (char c : w) present[c - 'a'] = 1;
        }

        // Build adjacency from word pairs
        for (int k = 1; k < words.size(); k++) {
            string &s1 = words[k - 1];
            string &s2 = words[k];

            int i = 0, j = 0;
            int m = s1.size(), n = s2.size();

            while (i < m && j < n && s1[i] == s2[j]) {
                i++;
                j++;
            }

            // If we reached end of s2 but s1 is longer → invalid
            if (j == n && m > n) return "";

            // If mismatch found, create edge s1[i] → s2[j]
            if (i < m && j < n) {
                adj[s1[i] - 'a'].push_back(s2[j] - 'a');
                indegree[s2[j] - 'a']++;
            }
        }

        // Topological Sort
        queue<int> q;
        int totalChars = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) totalChars++;
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";
        int processed = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u + 'a');
            processed++;

            for (int v : adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        if (processed != totalChars) return ""; // cycle
        return ans;
    }
};
