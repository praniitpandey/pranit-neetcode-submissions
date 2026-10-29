class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& a,const string& b){return a.size()<b.size();}); unordered_map<string,int> best; int answer=1; for(const string& word:words) { int length=1; for(int i=0;i<word.size();i++) { string previous=word.substr(0,i)+word.substr(i+1); auto it=best.find(previous); if(it!=best.end()) length=max(length,it->second+1); } best[word]=length; answer=max(answer,length); } return answer;
    }
};
