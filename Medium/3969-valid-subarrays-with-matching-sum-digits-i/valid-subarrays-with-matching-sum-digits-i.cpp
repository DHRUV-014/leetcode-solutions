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
    int first_digit(long long num){
        int fd=0;
        while(num>=10){
            num/=10;
        }
        return num;
        
    }
    int countValidSubarrays(vector<int>& nums, int x) {
       
        int left=0;
        int right=0;
        int ans=0;
        while(left<nums.size()){
            long long sum=0;
            int right=left;
            while(right<nums.size()){
                sum+=nums[right];
                if(sum%10==x and first_digit(sum)==x){
                    ans++;right++;
                }
                else{
                    right++;
                }
            }
            left++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    long long num = 1;
    auto __res = sol.first_digit(num);
    lcPrint(__res);
    cout << endl;
    return 0;
}
