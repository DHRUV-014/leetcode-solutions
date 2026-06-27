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
    int removeDuplicates(vector<int>& nums) {
        int start=0;
        int end=0;
        int result=0;
        while(end<nums.size()){
            if(nums[start]==nums[end]){
                end++;
            }
            else if(nums[start]!=nums[end]){
                result++;
                nums[result]=nums[end];
                start=end;
            }
        }
        return result+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    auto __res = sol.removeDuplicates(nums);
    lcPrint(__res);
    cout << endl;
    return 0;
}
