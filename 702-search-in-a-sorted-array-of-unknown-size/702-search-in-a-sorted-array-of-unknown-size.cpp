/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        //The start and end indices need to be determined before applying binary search
        int start = 0;
        int end = 1;
        if(reader.get(0) == target)
            return 0;
        while(reader.get(end) < target)
            end *= 2;
        start = end/2;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            int elem = reader.get(mid);
            if(elem == target)
                return mid;
            if(elem < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
};