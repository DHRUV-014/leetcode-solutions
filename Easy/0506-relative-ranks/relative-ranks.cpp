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
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ans(n);
        using p=pair<int,int>;
        priority_queue<p>h;
        for(int i=0;i<n;i++){
            h.push({score[i],i});
        }
        int count=0;
        while(!h.empty()){
            if(count==0){
                ans[h.top().second]="Gold Medal";
            }
            else if(count==1){
                ans[h.top().second]="Silver Medal";
            }
            else if(count==2){
                ans[h.top().second]="Bronze Medal";
            }
            else{
                ans[h.top().second]=to_string(count+1);
            }
            h.pop();count++;
            
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> score = {1, 2, 3};
    auto __res = sol.findRelativeRanks(score);
    lcPrint(__res);
    cout << endl;
    return 0;
}
