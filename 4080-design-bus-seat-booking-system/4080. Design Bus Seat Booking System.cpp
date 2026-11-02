class BusBooking {
    vector<vector<int>> book;
    int totalCost = 0;
    int numSeats = 0;
public:
    BusBooking(int n) {
        book.resize(n, vector<int>(4, 0));
    }
    
    void toggle(string seat) {
        int row = stoi(seat.substr(1)) - 1;
        char first = seat[0];
        int index = seat[0] - 'A';
        int cost = 0;
        if(first == 'B' || first == 'C' || (first == 'A' && !book[row][1]) || (first == 'D' && !book[row][2])) 
            cost = 1;
        else 
            cost = 3;
        if(book[row][index]) { // toggle
            // cost entry exists
            totalCost -= book[row][index];
            numSeats -= 1;
            book[row][index] = 0;
        } else {
            book[row][index] = cost;
            numSeats += 1;
            totalCost += cost;
        }
    }
    
    int getTotalTime() {
        return totalCost;
    }
    
    int getMinTime() {
        return numSeats;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */