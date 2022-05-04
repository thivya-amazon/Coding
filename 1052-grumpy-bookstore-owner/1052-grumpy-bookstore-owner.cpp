class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int angryCustomers = 0;
        int happyCustomers = 0;
       
        for(int i = 0; i < minutes; i++)
        {
            if(grumpy[i] == 1)
                angryCustomers += customers[i];
        }
        for(int i = 0; i < customers.size(); i++)
        {
            if(grumpy[i] == 0)
                happyCustomers += customers[i];
        }
        int maxAngryCustomers = angryCustomers;
        for(int i = minutes; i < customers.size(); i++)
        {
            if(grumpy[i] == 1)
                angryCustomers += customers[i];
            if(grumpy[i-minutes] == 1)
                angryCustomers -= customers[i-minutes];
            maxAngryCustomers = max(maxAngryCustomers, angryCustomers);             
        }
        return (maxAngryCustomers + happyCustomers);
    }
};