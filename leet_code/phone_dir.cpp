/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);

*/

class PhoneDirectory {
public:
    
    // This can be solved using set in C++
    set<int> mySet;
    int max;
    
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max = maxNumbers;
        for(int i=0; i<maxNumbers; i++){
            mySet.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(mySet.size()==0)
            return -1;
        
        auto it = mySet.begin();
        int res = *it;
        
        mySet.erase(it);
        
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return mySet.find(number) != mySet.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        mySet.insert(number);
    }
};



//unordered_set 
class PhoneDirectory {
 public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone
     directory. */
  PhoneDirectory(int maxNumbers) {
    for (int i = 0; i < maxNumbers; ++i) {
      numbers_.emplace(i);
    }
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (numbers_.empty()) {
      return -1;
    }
    int v = *numbers_.begin();
    numbers_.erase(numbers_.begin());
    return v;
  }

  /** Check if a number is available or not. */
  bool check(int number) { return numbers_.count(number); }

  /** Recycle or release a number. */
  void release(int number) { numbers_.emplace(number); }

 private:
  unordered_set<int> numbers_;
};

