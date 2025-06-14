// class Solution {
// public:
//     int openLock(vector<string>& deadends, string target) {
        
//     }
// };

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;

        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == target) return steps;

            for (int i = 0; i < 4; ++i) {
                for (int d = -1; d <= 1; d += 2) {
                    string next = current;
                    next[i] = (next[i] - '0' + d + 10) % 10 + '0';

                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};
