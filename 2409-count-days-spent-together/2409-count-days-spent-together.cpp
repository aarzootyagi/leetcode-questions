class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        auto days = [&](string s) {
            int m = stoi(s.substr(0,2)), day = stoi(s.substr(3,2));
            for(int i = 0; i < m-1; i++) day += d[i];
            return day;
        };
        int a = max(days(arriveAlice), days(arriveBob));
        int b = min(days(leaveAlice), days(leaveBob));
        return max(0, b-a+1);
    }
};