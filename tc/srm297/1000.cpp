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

const int MAXN = 10000;
double dp[MAXN];
const double INF = 999999999.9;

class RandomizedQuickSort {
    public:
        double get_ans(int listSize, int S, int a, int b) {
            if(listSize <= S){
                cout<<"return "<<b*listSize*listSize<<endl;
                return b*listSize*listSize;
            }
            if(dp[listSize]!=INF){
                return dp[listSize];
            }
            double tmp = 0;
            double prob = 1.0/listSize;
            for(int i=0; i<listSize; i++){
                double left = get_ans(i, S, a, b);
                double right = get_ans(listSize-i-1, S, a, b);
                tmp += prob*left + prob*right ; 
            }
            
            tmp += a*listSize;
            dp[listSize] = tmp;
            return tmp; 
        }
        double getExpectedTime(int listSize, int S, int a, int b) {
            for(int i=0; i<MAXN; i++)dp[i] = INF;
            double ans = get_ans(listSize, S, a,b);
            return ans;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
    cout << "]" << endl;
    RandomizedQuickSort *obj;
    double answer;
    obj = new RandomizedQuickSort();
    clock_t startTime = clock();
    answer = obj->getExpectedTime(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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

    int p0;
    int p1;
    int p2;
    int p3;
    double p4;

    {
        // ----- test 0 -----
        p0 = 1;
        p1 = 1;
        p2 = 1;
        p3 = 1;
        p4 = 1.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 2;
        p1 = 1;
        p2 = 1;
        p3 = 1;
        p4 = 3.0;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        p0 = 3;
        p1 = 1;
        p2 = 1;
        p3 = 1;
        p4 = 5.666666666666667;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 3;
        p1 = 1;
        p2 = 1;
        p3 = 10;
        p4 = 17.666666666666668;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 10;
        p1 = 5;
        p2 = 3;
        p3 = 2;
        p4 = 112.37380952380951;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
