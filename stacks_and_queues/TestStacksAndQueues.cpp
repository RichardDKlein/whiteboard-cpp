#include <iostream>

using namespace std;

void testQueueFromTwoStacks();
void testStackFromTwoQueues();

/**
 * @brief Test the classes in the "stacks_and_queues" folder.
 */
void testStacksAndQueues() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "              STACKS AND QUEUES              " << endl;
    cout << "=============================================" << endl;

    testQueueFromTwoStacks();
    testStackFromTwoQueues();
}
