class MovingAverage {
private:
deque<int> dq;
int window;
long long sum;
public:
    MovingAverage(int size) {
        this->window = size;
        this->sum = 0;
    }
    
    double next(int val) {
        if (this->dq.size() == window) {
            sum -= this->dq.back();
            this->dq.pop_back();
        }

        this->dq.push_front(val);
        this->sum += val;

        return (sum * 1.0) / (this->dq.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
