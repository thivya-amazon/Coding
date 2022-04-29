#define MAX_FORKS   5
class DiningPhilosophers {
private:
    pthread_mutex_t forksMtx[MAX_FORKS];
public:
    DiningPhilosophers() {
        for(int i = 0; i < MAX_FORKS; i++)
        {
            forksMtx[i] = PTHREAD_MUTEX_INITIALIZER;
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        if(philosopher % 2)
        {
            //lock the right fork first
            pthread_mutex_lock(&forksMtx[philosopher]);
            //lock the left fork second
            pthread_mutex_lock(&forksMtx[(philosopher+1) % MAX_FORKS]);     
        }
        else
        {
            //lock the left fork first
            pthread_mutex_lock(&forksMtx[(philosopher+1) % MAX_FORKS]);            
            //lock the right fork second
            pthread_mutex_lock(&forksMtx[philosopher]);
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        pthread_mutex_unlock(&forksMtx[(philosopher+1) % MAX_FORKS]);
        putRightFork();
        pthread_mutex_unlock(&forksMtx[philosopher]);	
    }
};