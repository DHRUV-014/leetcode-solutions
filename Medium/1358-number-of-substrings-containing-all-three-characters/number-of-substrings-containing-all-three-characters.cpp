#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

template<typename T> void lcPrint(const T& x) { cout << x; }
inline void lcPrint(bool b) { cout << (b ? "true" : "false"); }
inline void lcPrint(const string& s) { cout << '"' << s << '"'; }
template<typename T> void lcPrint(const vector<T>& v) {
    cout << '['; for (size_t i = 0; i < v.size(); ++i) { if (i) cout << ','; lcPrint(v[i]); } cout << ']';
}
template<typename A, typename B> void lcPrint(const pair<A,B>& p) {
    cout << '('; lcPrint(p.first); cout << ','; lcPrint(p.second); cout << ')';
}

class Solution {
public:
    int numberOfSubstrings(string s) {
        int num=0;
        int left=0;
        int right=0;
        int a=0,b=0,c=0;
        
        while(right<s.length()){
            if(s[right]=='a')a++;
            else if(s[right]=='b')b++;
            else c++;
            
            while(a>=1 and b>=1 and c>=1){
                num+=s.length()-right;
                if(s[left]=='a')a--;
                else if(s[left]=='b')b--;
                else c--;
                left++;
            }
            
            right++;

        }

        
        return num;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    auto __res = sol.numberOfSubstrings(s);
    lcPrint(__res);
    cout << endl;
    return 0;
}
