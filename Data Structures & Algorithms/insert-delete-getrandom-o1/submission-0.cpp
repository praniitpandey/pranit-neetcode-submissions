class RandomizedSet {
public:
    vector<int> array;
    unordered_map<int, int> index;

    RandomizedSet() {}
    
    bool insert(int val) {
        if (index.count(val))
            return false;

        index[val] = array.size();
        array.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if (!index.count(val))
            return false;

        int removeIndex = index[val], lastVal = array.back();

        index[lastVal] = index[val];
        index.erase(val);

        array[removeIndex] = lastVal;
        array.pop_back();

        return true;   
    }
    
    int getRandom() {
        return array[rand() % array.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */