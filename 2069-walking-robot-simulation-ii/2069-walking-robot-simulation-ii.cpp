class Robot {
public:
    int w, h,perimeter;
    int pos=0;
    bool moved=false;

    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w - 1) + 2 * (h - 1);
    }

    void step(int num) {
        moved = true;
        pos = (pos + num) % perimeter;
    }

    vector<int> getPos() {
        if (pos <= w - 1)
            return {pos, 0};
        if (pos <= (w - 1) + (h - 1))
            return {w - 1, pos - (w - 1)};
        if (pos <= 2 * (w - 1) + (h - 1))
            return {(w - 1) - (pos - (w - 1) - (h - 1)), h - 1};

        return {0, (h - 1) - (pos - 2 * (w - 1) - (h - 1))};
    }

    string getDir() {
        if (!moved)
            return "East";
        if (pos == 0)
            return "South";
        if (pos <= w - 1)
            return "East";
        if (pos <= (w - 1) + (h - 1))
            return "North";
        if (pos <= 2 * (w - 1) + (h - 1))
            return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */