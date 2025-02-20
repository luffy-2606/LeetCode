class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string a="";
        int ans=0;
       for(int i=0;i<s.size();i++){
         if(a.find(s[i])!=string::npos) {
            auto y=find(a.begin(),a.end(),s[i]);
            a.erase(a.begin(),y+1);}
            a.push_back(s[i]);
         int t=a.size();
         ans=max(ans,t);} 
       return ans;
    }
};