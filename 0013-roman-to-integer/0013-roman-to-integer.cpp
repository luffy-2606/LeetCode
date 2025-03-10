class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='I'){
                if(i+1!=n && s[i+1]=='V'){
                    ans--;
                    continue;
                }
                if(i+1!=n && s[i+1]=='X'){
                    ans--;
                    continue;
                }
                ans+=1;
            }
            if(s[i]=='V'){
                ans=ans+5;
            }
            if(s[i]=='X'){
                
                if(i+1!=n && s[i+1]=='L'){
                    ans-=10;
                    continue;
                }
                if(i+1!=n && s[i+1]=='C'){
                    ans-=10;
                    continue;
                }
                ans+=10;
            }
            if(s[i]=='L'){
                ans=ans+50;
            }
            if(s[i]=='C'){
                
                if(i+1!=n && s[i+1]=='D'){
                    ans-=100;
                    continue;
                }
                if(i+1!=n && s[i+1]=='M'){
                    ans-=100;
                    continue;
                }
                ans+=100;
            }
            if(s[i]=='D'){
                ans=ans+500;
            }
            if(s[i]=='M'){
                ans=ans+1000;
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};