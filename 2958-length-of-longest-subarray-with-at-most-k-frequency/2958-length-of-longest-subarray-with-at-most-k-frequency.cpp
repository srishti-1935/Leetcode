template<int SIZE>
class FastMap {
private:
    int keys[SIZE];
    int values[SIZE];
    bitset<SIZE> used;
    int idx[100003]; 
    int cnt;

    inline int hash(int key) __attribute__((always_inline)) {
        unsigned h=(unsigned)key*0x45d9f3b1;
        return h%SIZE;
    }

public:
    FastMap() : cnt(0) {}

    void clear() {
        for (int i=0; i<cnt; i++) {
            used[idx[i]]=0;
        }
        cnt=0;
    }

    void put(int key, int value) {
        int h=hash(key);
        while (used[h] && keys[h]!=key) {
            h++;
            if (h==SIZE) h=0;
        }
        if (!used[h]) {
            used[h]=1;
            keys[h]=key;
            idx[cnt++]=h;
        }
        values[h]=value;
    }

    int get(int key, int default_val = -1) {
        int h=hash(key);
        while (used[h]) {
            if (keys[h]==key) return values[h];
            h++;
            if (h==SIZE) h=0;
        }
        return default_val;
    }

    inline int size() const { return cnt; }
    inline int operator[](int i) const { 
        return values[idx[i]]; 
    }
};

FastMap<200003> freq;
class Solution {
public:
    static int maxSubarrayLength(vector<int>& nums, int k) {
        const int n=nums.size();
        int cnt=0;
        for (int l=0, r=0; r<n; r++){
            const int x=nums[r];
            int f=freq.get(x, 0)+1;
            freq.put(x, f);
            while (f>k){
                const int y=nums[l++];
                freq.put(y, freq.get(y, 0)-1);
                f=freq.get(x, 0);
            }
        
            cnt=max(cnt,r-l+1);// max len
        }
        freq.clear();
        return cnt;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();