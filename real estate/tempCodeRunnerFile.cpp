#include <iostream>
using namespace std;


class Distance {
    int kilometers;
    int meters;
public:
    Distance(int m=0) {
        kilometers = m / 1000;
        meters = m % 1000;
    }
    Distance(int km, int m) {
        kilometers = km;
        kilometers += m / 1000;
        meters = m % 1000;
    }
    void print() const {
        cout << kilometers << "km "
             << meters << "m";
    }
    friend Distance operator+(const Distance&, int);
};



class Weight {
    int kilograms;
    int grams;
public:
    Weight(int g=0) {
        kilograms = g / 1000;
        grams = g % 1000;
    }
    Weight(int kg, int g) {
        kilograms = kg;
        kilograms += g / 1000;
        grams = g % 1000;
    }
    Weight operator-(int) const;
    void print() const {
        cout << kilograms << "kg "
             << grams << "g";
    }
};


Distance operator+(const Distance& d, int m) {
    int dist = d.kilometers*1000 + d.meters + m;
    return Distance(dist);
}


Weight Weight::operator-(int g) const {
    int weight = kilograms*1000 + grams - g;
    return Weight(weight);
}


int main() {
    Distance d(20, 420);
    Distance new_dist = d + 678;
    d.print();
    cout << " + 678m = ";
    new_dist.print();
    cout << endl;

    Weight w(45, 950);
    Weight new_weight = w - 543;
    w.print();
    cout << " - 543g = ";
    new_weight.print();
    cout << endl;

    return 0;
}