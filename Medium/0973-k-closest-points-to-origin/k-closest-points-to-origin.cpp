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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using p=pair<double,pair<int,int>>; 
        priority_queue<p> h;
        
        for(int i=0;i<points.size();i++){
            double distance=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            h.push({distance,{points[i][0],points[i][1]}});
            if(h.size()>k){
                h.pop();
            }
        }

        vector<vector<int>>ans;
        while(!h.empty()){
            ans.push_back({h.top().second.first,h.top().second.second});
            h.pop();
        }

        return ans;


    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 2, 3}, {1, 2, 3}};
    int k = 1;
    auto __res = sol.kClosest(points, k);
    lcPrint(__res);
    cout << endl;
    return 0;
}
