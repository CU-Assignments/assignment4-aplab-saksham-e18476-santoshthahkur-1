#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, pair<int, int>>> events;

    for (auto& b : buildings) {
        events.push_back({b[0], {-b[2], b[1]}});  
        events.push_back({b[1], {b[2], 0}});      
    }

    sort(events.begin(), events.end());

    multiset<int> activeHeights = {0};  
    vector<vector<int>> result;
    int prevMaxHeight = 0;

    for (auto& event : events) {
        int x = event.first;
        int height = event.second.first;
        int right = event.second.second;

        if (height < 0) {
            activeHeights.insert(-height);
        } else {
            activeHeights.erase(activeHeights.find(height));
        }

        int currentMaxHeight = *activeHeights.rbegin();

        if (currentMaxHeight != prevMaxHeight) {
            result.push_back({x, currentMaxHeight});
            prevMaxHeight = currentMaxHeight;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> skyline = getSkyline(buildings);

    for
