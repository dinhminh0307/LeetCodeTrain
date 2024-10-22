class RandomizedSet {
private:
    std::unordered_set<int> mp;              // Stores the elements
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        mp.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        mp.erase(val); 
        return true;
    }
    
    /**
     * convert the current set to vector and randomeize it
     */
    int getRandom() {
        vector<int> v;
        v.assign(mp.begin(), mp.end());
        int randomIndex = rand() % v.size();
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */