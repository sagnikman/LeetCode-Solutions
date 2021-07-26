//Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> codes{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> dfs(string digits) {
        vector<string> sendResult;
        if(digits.empty()) {
        sendResult.push_back("");
        return sendResult;
        }
        char firstDigit=digits[0];
        string restOfString=digits.substr(1);
        
        vector<string> recursionResult=dfs(restOfString);
        string codeForFirstDigit=codes[firstDigit - '0'];
        
        for(auto letter: codeForFirstDigit) {
            for(auto &str : recursionResult) {
                sendResult.push_back(letter + str);
            }    
        }
        return sendResult;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string> {};
        return dfs(digits);
    }
};
