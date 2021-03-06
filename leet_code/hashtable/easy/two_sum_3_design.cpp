/*

Two Sum III - Data structure design

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

*/

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        mSet.insert(number);
        
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto it = mSet.begin(); it != mSet.end(); it++)
        {
            int other = value - *it;
            int count = 0;
            //Look how count is used to distinguish a case where the number
            // added can be twice or a single number is added and the target
            // is equal to it. 
            if (other == *it) {
                count = 1;
            }
            if(mSet.count(other) > count) {return true;}
        }
        return false;
    }
    unordered_multiset<int> mSet;
};
