class MedianFinder {
public:
vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = lower_bound(arr.begin(), arr.end(), num);
        arr.insert(it, num);
    }
    
    double findMedian() {
        int n = arr.size();
        if (n % 2) return arr[n / 2];
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */