class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Make Adjacency List
        vector<vector<int>> aList(numCourses);
        for (auto p : prerequisites)
            aList[p[1]].push_back(p[0]);

        // Make indegree
        vector<int> iDegree(numCourses, 0);
        for (auto c : aList)
            for (int i = 0; i < c.size(); ++i)
                iDegree[c[i]]++;

        // Add indegree == 0 to queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (iDegree[i] == 0)
                q.push(i);

        // Process queue
        vector<int> ans;
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for (auto p : aList[course]) {
                iDegree[p]--;

                if (iDegree[p] == 0)
                    q.push(p);
            }
        }

        // If all courses are included, return answer
        if (ans.size() == numCourses)
            return ans;

        // Otherwise, cycle exists
        return vector<int>{};
    }
};