#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
	vector<string> res;
	
	bool isValid(string& s, int start, int end) {
		if (start > end) return false;
		
        // 不含前导0
		if (s[start] == '0' && start != end) return false;
		
		// 数字不大于255， 且字符必须是数组
		int num = 0;
		for(int i = start; i<= end; i++) {
			if (s[i] > '9' && s[i] < '0') {
				return false;
			}
			
			num = num*10 + (s[i] - '0');
			if (num > 255) return false;
		}
        return true;
	}
	
	void dfs(string& s, int startIndex, int pointNum) {
		if (pointNum == 3) {
		// 当已有4个地址时，只需判断最后一个地址是否有效，有效则保存
			if (isValid(s, startIndex, s.size()-1)) {
				res.push_back(s);
			}
			return;
		}
		
		for (int i = startIndex; i < s.size(); i++ ) {
			if (isValid(s, startIndex, i)) {
				pointNum++;
				s.insert(s.begin()+i+1, '.');
				dfs(s, i+2, pointNum);
				s.erase(s.begin()+i+1);
				pointNum--;
			}
			else break;
		}
	}
	vector<string> restoreIpAddresses(string s) {
        res.clear();
        dfs(s, 0, 0);
        return res;
    }
};

void printV(vector<string> s) {
    for (int i = 0; i < s.size(); i++ ) {
        cout << s[i] << endl ;
    }
}

int main() {

    string  a = "25525511135";
    Solution S;


    vector<string> ans = S.restoreIpAddresses(a);
    printV(ans);


    return 0;
}

