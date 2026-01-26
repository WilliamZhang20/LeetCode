#include <mutex>
#include <functional>

class TrafficLight {
private:
    // Tracks which road currently has the green light
    int greenRoad;
    std::mutex mtx;

public:
    TrafficLight() {
        greenRoad = 1; // Initial state: Road 1 is green
    }

    void carArrived(
        int carId,           // ID of the car
        int roadId,          // ID of the road the car is on (1 or 2)
        int direction,       // Direction of the car
        std::function<void()> turnGreen,  // Function to turn light green
        std::function<void()> crossCar    // Function to let car cross
    ) {
        // Lock the mutex to ensure only one car processes the light at a time
        std::lock_guard<std::mutex> lock(mtx);
        
        // If the light is not green for this car's road, toggle it
        if (greenRoad != roadId) {
            turnGreen();
            greenRoad = roadId;
        }
        
        // The car can now safely cross
        crossCar();
    }
};