class ParkingSystem {
public:
    int big;
    int medium;
    int small;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1){
            big--;
            if (big < 0) return false;
            else {
                return true;
            }
        }
        else if (carType == 2){
            medium--;
            if (medium < 0) return false;
            else {
                return true;
            }
        }
        else {
            small--;
            if (small < 0) return false;
            else {
                return true;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */