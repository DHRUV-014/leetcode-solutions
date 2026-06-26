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

class compare{
public:
    bool operator()(int a , int b){
        return a<b;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,compare>h;
        
        for(int i=0;i<stones.size();i++){
            h.push(stones[i]);
        }
        
        if(h.size()==1){
            return h.top();
        }

        while(h.size()>1){
            int y=h.top();
            h.pop();
            int x=h.top();
            h.pop();
            if(y>x){
                y=y-x;
                h.push(y);
            }
            
        }

        if(h.empty()){
            return 0;
        }
        else{
            return h.top();
        }
        
    }
};

int main() {
    Solution sol;
    vector<int> stones = {1, 2, 3};
    auto __res = sol.lastStoneWeight(stones);
    lcPrint(__res);
    cout << endl;
    return 0;
}
