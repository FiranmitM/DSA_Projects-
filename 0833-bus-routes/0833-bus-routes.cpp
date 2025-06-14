class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stop_to_buses;
        int n = routes.size();

        // Build the map: stop -> list of buses (by index) that pass through this stop
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stop_to_buses[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visited_stops;
        unordered_set<int> visited_buses;

        q.push(source);
        visited_stops.insert(source);

        int buses_taken = 0;

        while (!q.empty()) {
            int level_size = q.size();
            ++buses_taken;

            for (int i = 0; i < level_size; ++i) {
                int curr_stop = q.front(); q.pop();

                // Explore all buses passing through this stop
                for (int bus : stop_to_buses[curr_stop]) {
                    if (visited_buses.count(bus)) continue;
                    visited_buses.insert(bus);

                    // Explore all stops this bus goes through
                    for (int next_stop : routes[bus]) {
                        if (next_stop == target) return buses_taken;
                        if (visited_stops.count(next_stop)) continue;
                        visited_stops.insert(next_stop);
                        q.push(next_stop);
                    }
                }
            }
        }

        return -1; // target not reachable
    }
};
