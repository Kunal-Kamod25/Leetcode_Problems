class Solution {
public:
    string reorganizeString(string s) {
        int sz = s.size();
        int freq[26] = {0};
        
        for(int i = 0; i < sz; i++) {
            freq[s[i]- 'a']++;
        }

        priority_queue<pair<int , char>> heap;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0)
                continue;
            heap.push({freq[i] , char(i + 'a')});
        }
        string ans;
        pair<int , char> prev={0 , '#'};
        while(!heap.empty()) 
        {
            auto[freq , ch] = heap.top();
            heap.pop();
            ans += ch;
            freq --;

            if(prev.first > 0)
                heap.push(prev);
            prev = {freq , ch};
        }
         if(prev.first > 0)
            return "";
        return ans;
    }
};