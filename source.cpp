#include <iostream>
using namespace std;

class LaptopCharger {
public:
    virtual void chargeLaptop() = 0; 
    virtual ~LaptopCharger() = default;
};

// new wagon
class NewVagonSystem : public LaptopCharger {
public:
    void MatchSocket() {
        cout << "Laptop is charging using new wagon system." << endl;
    }
    void chargeLaptop() override {
        MatchSocket();
    }
};

// old wagon
class OldVagonSystem {
public:
    void ThinSocket() {
        cout << "Old wagon system is providing power." << endl;
    }
};


class Adapter : public LaptopCharger {
private:
    OldVagonSystem* oldSystem;

public:
    Adapter(OldVagonSystem* oldSys) : oldSystem(oldSys) {}

    void chargeLaptop() override {
        cout << "Adapter is connecting to old wagon system..." << endl;
        oldSystem->ThinSocket();
    }
};


int main() {
    // new wagon without adpter
    cout << "Testing new wagon system:\n";
    NewVagonSystem newWagon;
    newWagon.chargeLaptop();

    // old wagon with adpter
    cout << "\nTesting old wagon system with adapter:\n";
    OldVagonSystem oldWagon;
    Adapter adapter(&oldWagon);
    adapter.chargeLaptop();

    return 0;
}
