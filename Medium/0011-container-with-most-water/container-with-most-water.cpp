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
    int maxArea(vector<int>& height) {
        int indx_left = 0;
        int indx_right = height.size() - 1;
        int ans = 0;

        while(indx_left < indx_right){
            int width = indx_right - indx_left;
            int min_height=min(height[indx_left],height[indx_right]);
            ans = max(ans,min_height* width);

            if(height[indx_left] < height[indx_right]){
                indx_left++;
                
            }
            else{
                indx_right--;
            }

            
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1, 2, 3};
    auto __res = sol.maxArea(height);
    lcPrint(__res);
    cout << endl;
    return 0;
}
