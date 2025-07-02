class Solution {
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    set<string> seen;

public:
    void allLcs(const string& s1, const string& s2, string str)
    {
        if (s1.length() == 0 || s2.length() == 0)
        {
            if (seen.count(str)) return;
            seen.insert(str);

            if (pq.empty())
            {
                pq.push({str.length(), str});
            }
            else
            {
                auto x = pq.top();
                int curLen=x.first;
                if (str.length() > curLen)
                {
                    while (!pq.empty()) pq.pop();
                    pq.push({str.length(), str});
                }
                else if (str.length() == curLen)
                {
                    pq.push({str.length(), str});
                }
            }
            return;
        }

        if (s1[0] == s2[0])
             return allLcs(s1.substr(1), s2.substr(1), str + s1[0]);

        allLcs(s1, s2.substr(1), str);
        allLcs(s1.substr(1), s2, str);
    }

    vector<string> allLCS(string &s1, string &s2) {
        vector<string> v;

        allLcs(s1, s2, "");

        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            v.push_back(x.second);
        }

        return v;
    }
};
