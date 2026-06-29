class Solution {
public:
    bool isCyclePresentFor(int idx, vector<vector<int>>& aList, vector<int>& v) {

        if (v[idx] == 1)      // Cycle Present
            return true;

        if (v[idx] == 2)      // Already Visited
            return false;

        v[idx] = 1;

        for (auto e : aList[idx]) {
            if (isCyclePresentFor(e, aList, v))
                return true;
        }

        v[idx] = 2;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Step 1 : HLA

        // Create Adjacency List
        vector<vector<int>> aList(numCourses);

        // Create Visited Array
        // 0 - Unvisited
        // 1 - Visiting
        // 2 - Visited
        vector<int> v(numCourses, 0);

        // Creating Adjacency List
        for (auto p : prerequisites) {
            aList[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (isCyclePresentFor(i, aList, v))
                return false;
        }

        return true;
    }
};