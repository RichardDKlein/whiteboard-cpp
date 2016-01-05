#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance_;
    Singleton() {
        // construction logic
    }
public:
    static Singleton* instance() {
        if (instance_ == nullptr) {
            instance_ = new Singleton();
        }
        return instance_;
    }
};

Singleton* Singleton::instance_ = nullptr;

void testSingleton() {
    cout << endl;
    cout << "Test Singleton:" << endl;
    cout << "===============" << endl;

    Singleton* instance1 = Singleton::instance();
    Singleton* instance2 = Singleton::instance();

    cout << "1st time: Singleton::instance() = "
         << instance1 << endl;
    cout << "2nd time: Singleton::instance() = "
         << instance2 << endl;
}
