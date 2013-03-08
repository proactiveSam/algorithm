#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int MAXN = 51;
int g[MAXN][MAXN];
const int INF = 999999999;
typedef pair<int, int> pii;

int get_minutes(int node, int sz){
    bool is_leaf = true;
    for(int i=0; i<sz; i++){
        if(g[node][i]!=INF){
            is_leaf = false;break;
        }
    }
    if(is_leaf){
        return 0;
    }

    vector< pii > mins;
    for(int i=0; i<sz; i++){
        if(g[node][i]!=INF){
            int temp_minutes = get_minutes(i, sz);
            mins.push_back( pii(temp_minutes, i) );
        }
    }
    sort(mins.begin(), mins.end());
    reverse(mins.begin(), mins.end());
    int t_max = -INF;
    for(int i=0; i<mins.size(); i++){
        cout<<"number "<<mins[i].second<<" is "<<mins[i].first+i+1<<endl;
        t_max = max(t_max, mins[i].first+i+1);
    }
    cout<<"at node "<<node<<" return "<<t_max<<endl;
    return t_max;
}


class SpreadingNews {
    public:
        int minTime(vector <int> supervisors) {
            for(int i=0; i<MAXN; i++)for(int j=0; j<MAXN; j++){
                g[i][j]=INF;
            }

            for(int i=1; i<supervisors.size(); i++){
                g[supervisors[i]][ i] = 1;
            }
            return get_minutes(0, supervisors.size());
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    SpreadingNews *obj;
    int answer;
    obj = new SpreadingNews();
    clock_t startTime = clock();
    answer = obj->minTime(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    vector <int> p0;
    int p1;

    {
        // ----- test 0 -----
        int t0[] = {-1,0,0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {-1,0,0,2,2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {-1,0,1,2,3};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 4;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {-1,0,0,1,1,1,2,2,3,3,4,4,5,5,6,7,7,8,12,13,14,16,16,16};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 7;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING