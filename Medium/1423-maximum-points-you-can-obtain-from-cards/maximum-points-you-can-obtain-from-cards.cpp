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

    int maxScore(vector<int>& cardPoints, int k) {
        
        if(k==cardPoints.size()){
            int sum=0;
            for(int i=0;i<cardPoints.size();i++){
                sum+=cardPoints[i];
            }
            return sum;
        }

        
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int ans=sum;
        int left=k-1;
        int right=cardPoints.size()-1;
        while(left>=0){
            sum-=cardPoints[left];
            sum+=cardPoints[right];
            ans=max(ans,sum);
            left--;
            right--;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints = {1, 2, 3};
    int k = 1;
    auto __res = sol.maxScore(cardPoints, k);
    lcPrint(__res);
    cout << endl;
    return 0;
}
