#include <pthread.h>
class ZeroEvenOdd {
private:
    int n;
    bool zeroFlag;
    bool oddFlag;
    pthread_mutex_t mx;
    pthread_cond_t condZero;
    pthread_cond_t condNonZero;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        zeroFlag    = true;
        oddFlag     = false;
        mx          = PTHREAD_MUTEX_INITIALIZER;
        condZero    = PTHREAD_COND_INITIALIZER;
        condNonZero = PTHREAD_COND_INITIALIZER;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
       
        for(int i = 1; i <= n; i++)
        {
            pthread_mutex_lock(&mx);
            while(!zeroFlag)
                pthread_cond_wait(&condZero, &mx);
            printNumber(0);
            if(i % 2)
            {
                oddFlag = true;                
            }
            else
            {
                oddFlag = false;
            }
            zeroFlag = false;
            pthread_cond_signal(&condNonZero);            
            pthread_mutex_unlock(&mx);    
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i+=2)
        {
            pthread_mutex_lock(&mx);
            while(zeroFlag || oddFlag)
                pthread_cond_wait(&condNonZero, &mx);
            
            printNumber(i);
            zeroFlag = true;
            pthread_cond_signal(&condZero);
            pthread_mutex_unlock(&mx);
            
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i+=2)
        {
            pthread_mutex_lock(&mx);
            while(zeroFlag || !oddFlag)
                pthread_cond_wait(&condNonZero, &mx);
            printNumber(i);
            zeroFlag = true;
            pthread_cond_signal(&condZero);
            pthread_mutex_unlock(&mx);
        }
    }
};