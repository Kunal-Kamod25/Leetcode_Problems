class Solution {
public:

    double getDistance(vector<int> &pt) {

        double d = (pt[0] * pt[0]) + (pt[1] * pt[1]);

        return sqrt(d);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int rows = points.size();

        priority_queue<
            pair<double, int>,
            vector<pair<double, int>>,
            greater<pair<double, int>>
        > minHeap;

        for(int i = 0; i < rows; i++) {

            double dist = getDistance(points[i]);

            minHeap.push({dist, i});
        }

        vector<vector<int>> ans;

        for(int i = 0; i < k; i++) {

            pair<double, int> tmp = minHeap.top();

            ans.push_back(points[tmp.second]);

            minHeap.pop();
        }

        return ans;
    }
};