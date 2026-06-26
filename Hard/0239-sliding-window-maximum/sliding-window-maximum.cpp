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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        using p=pair<int,int>;
        priority_queue<p>h;
        int left=0;
        int right=k-1;
        int sw_len=0;
        for(int i=left;i<=right;i++){
            h.push({nums[i],i});
        }
        vector<int>ans;
        ans.push_back(h.top().first);
        while(right<nums.size()-1){

            left++;right++;
            h.push({nums[right],right});

            while(!h.empty() and h.top().second<left){
                h.pop();
            }
            ans.push_back(h.top().first);
            
        }
        return ans;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 1;
    auto __res = sol.maxSlidingWindow(nums, k);
    lcPrint(__res);
    cout << endl;
    return 0;
}
