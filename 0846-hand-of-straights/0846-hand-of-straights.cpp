class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[hand[i]]++;
        }
        priority_queue<int , vector<int>, greater<int>> pq;
        for(auto i : freq){
            pq.push(i.first);
        }
        while(!pq.empty()){
            int start = pq.top();
            for(int i=0; i<groupSize; i++){
                if(freq[start + i] == 0) return false;
                freq[start + i]-- ;
            }
            while(!pq.empty() && freq[pq.top()] == 0){
                pq.pop();
            }
        }
        return true;
    }
};