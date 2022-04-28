class TrafficLight {
public:
    int greenRoadId;
    pthread_mutex_t m;
    TrafficLight() {
        greenRoadId = 1;
        m = PTHREAD_MUTEX_INITIALIZER;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        pthread_mutex_lock(&m);
        if(roadId != greenRoadId)
        {
            turnGreen();
            greenRoadId = roadId;
        }
        crossCar();
        pthread_mutex_unlock(&m);
    }
};