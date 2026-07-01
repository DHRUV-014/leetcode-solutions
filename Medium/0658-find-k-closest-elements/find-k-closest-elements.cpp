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
    bool operator()(int a,int b){
        return a>b;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        using p=pair<int,int>;
        priority_queue<p,vector<p>,greater<p>>h;
        for(int i=0;i<arr.size();i++){
            int dist=abs(arr[i]-x);
            h.push({dist,arr[i]});
        }
        vector<int>ans;
        priority_queue<int,vector<int>,compare> h1;
        while(k>0){
            h1.push(h.top().second);
            h.pop();
            k--;
        }
        while(!h1.empty()){
            ans.push_back(h1.top());
            h1.pop();
        }
        return ans;



    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int k = 1;
    int x = 1;
    auto __res = sol.findClosestElements(arr, k, x);
    lcPrint(__res);
    cout << endl;
    return 0;
}
