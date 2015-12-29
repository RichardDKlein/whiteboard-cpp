#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton* m_instance;
    Singleton() {
        // construction logic
    }
public:
    static Singleton* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
        return m_instance;
    }
};

Singleton* Singleton::m_instance = nullptr;

void testSingleton() {
    cout << endl;
    cout << "Test Singleton:" << endl;
    cout << "===============" << endl;

    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();

    cout << "1st time: Singleton::getInstance() = "
         << instance1 << endl;
    cout << "2nd time: Singleton::getInstance() = "
         << instance2 << endl;
}
