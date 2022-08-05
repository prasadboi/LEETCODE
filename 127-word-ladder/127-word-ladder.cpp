class Solution {
public:
    #define ll long long int
    #define vstr vector<string>
    #define sstr set<string>
    #define vb vector<bool>
    #define umap unordered_map
    #define uset unordered_set
    
    sstr wordListDict;
    
    vstr nextNode(string s)
    {
        // generate all possible next substrings
        vstr res;
        for(auto i = 0; i < s.size(); i++)
        {
            for(char j = 'a'; j <= 'z'; j++)
            {
                char x = s[i];    
                s[i] = j;
                if(wordListDict.count(s) > 0 and j != x)
                    res.push_back(s);
                s[i] = x;
            }
        }
        return res;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // put all the words of wordlist in a dictionary
        
        for(auto i : wordList) wordListDict.insert(i);
        
        // run bfs
        queue<string> q;
        map<string, ll> dist;
        map<string, bool> vis;
        
        q.push(beginWord);
        while(!q.empty())
        {
            string w = q.front(); q.pop();
            if(w == endWord) return dist[endWord]+1;
            for(auto i : nextNode(w))
            {
                // cout<<"w : "<<w<<", i : "<<i<<endl;
                if(vis[i] == true) continue;
                vis[i] = true;
                dist[i] = dist[w] + 1;
                q.push(i);
            }
        }
        return 0;
    }
};