class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int sz1=w1.size();
        int sz2=w2.size();

        string ans="";
        int i=0, j=0;
        while(i<sz1 && j<sz2)
        {
            ans=ans+w1[i];
            ans=ans+w2[j];
            i++;
            j++;
        }
        if(i<sz1)
        {
            while(i<sz1)
            {
                ans+=w1[i];
                i++;
            }
        }
        else
        {
            if(j<sz2)
            {
                while(j<sz2)
                {
                    ans+=w2[j];
                    j++;
                }
            }
        }
        return ans;
    }
};