vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        unordered_map<string,vector<string>> result;
        for(const string& word : strs){
            string sortedWord = word;
            sort(sortedWord.begin(),sortedWord.end());
            result[sortedWord].push_back(word);
        }
        vector<vector<string>> answer;
        for(const auto& group: result){
            answer.push_back(group.second);
        }
        return answer;
    }
