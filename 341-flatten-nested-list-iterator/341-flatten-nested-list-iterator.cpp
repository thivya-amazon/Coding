/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flatList;
    int index;
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        flattenLevels(nestedList);
    }
    
    int next() {        
        return flatList[index++];       
    }
    
    bool hasNext() {
       if(index < flatList.size())
           return true;
        return false;
    }
    
    void flattenLevels(vector<NestedInteger> &nestedList)
    {
        for(auto nestedInt : nestedList)
        {
            if(nestedInt.isInteger())
                flatList.push_back(nestedInt.getInteger());
            else
            {
                auto listInt = nestedInt.getList();
                flattenLevels(listInt);
            }
                
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */