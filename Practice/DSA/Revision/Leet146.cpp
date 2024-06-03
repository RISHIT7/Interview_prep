class LRUCache {
    unordered_map<int, pair<int, long long int>> lru;
    int size;
    int req;

public:
    LRUCache(int capacity) {
        size = capacity;
        req = 0;
    }

    int get(int key) {
        if (lru.find(key) == lru.end()) {
            return -1;
        }
        lru[key].second = req;
        req += 1;
        return lru[key].first;
    }

    void put(int key, int value) {
        // key exists
        if (lru.find(key) != lru.end()) {
            lru[key] = {value, req};
            req += 1;
            return;
        }
        
        // size not filled
        if (size > 0) {
            lru[key] = {value, req};
            req += 1;
            size -= 1;
        }

        else {
            // size filled and key does not exist
            long long int min_req = INT_MAX;
            for (auto i = lru.begin(); i != lru.end(); i++) {
                if (min_req > i->second.second) {
                    min_req = i->second.second;
                }
            }

            for (auto i = lru.begin(); i != lru.end(); i++) {
                if (i->second.second == min_req) {
                    lru.erase(i);
                    break;
                }
            }
            lru[key] = {value, req};
            req += 1;
        }
        cout << size << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
