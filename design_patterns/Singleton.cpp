#include <cstdio>

class Singleton {
public:
    static Singleton* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
        return m_instance;
    }
private:
    Singleton() {
        // construction logic
    }
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

void testSingleton() {
    printf("\n");
    printf("Test Singleton:\n");
    printf("===============\n");

    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();
    printf("1st time: Singleton::getInstance() = %p\n", instance1);
    printf("2nd time: Singleton::getInstance() = %p\n", instance2);
}
