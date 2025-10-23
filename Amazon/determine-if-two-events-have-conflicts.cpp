class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string Astart = event1[0].substr(0,2) + event1[0].substr(3);
        string Aend = event1[1].substr(0, 2) + event1[1].substr(3);
        string Bstart = event2[0].substr(0, 2) + event2[0].substr(3);
        string Bend = event2[1].substr(0, 2) + event2[1].substr(3);
        return Astart <= Bend  &&  Bstart <= Aend;
    }
};