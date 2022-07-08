class Solution {
public:
    #define vstr vector<string> 
    #define vi vector<int>
    #define umapss unordered_map<string, string>
    #define umapsb unordered_map<string, bool>
    #define umapsi unordered_map<string, int>
    // this function is the important bit
    vstr nextNode(string word)
    {
        vstr res;
        for(int i = 0; i < word.size(); i++)
        {
            for(int ch = 'a'; ch < 'z' + 1; ch++)
            {
                string temp = word;
                temp[i] = ch; 
                res.push_back(temp);
            }
        }
        return res;
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        set<string> words;
        for(auto i : wordList) words.insert(i);
        
        queue<string> q;
        umapsb vis;
        umapsi dist;
        q.push(beginWord);
        vis[beginWord] = true;
        while(!q.empty()){
            string u = q.front(); q.pop();
            // cout<<"at node : "<<u<<"| at dist : "<<dist[u]<<endl;
            if(u == endWord) return dist[u]+1;

            for(auto i : nextNode(u)){
                // if not visited and it is a valid word from the dictionary
                if((vis.find(i) == vis.end() or vis[i] == false) and (words.find(i) != words.end())){
                    vis[i] = true;
                    q.push(i);
                    dist[i] = dist[u] + 1;
                }
            }
        }
        return 0;
    }
};