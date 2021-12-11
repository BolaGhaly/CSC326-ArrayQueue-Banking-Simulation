//Bola Ghaly
//Lab 5 - Banking Simulation using array-based implementation
#include "ArrayQueue.h"
#include <iostream>
#include <string>
using namespace std;

void insertQueue(QueueInterface<string>* queuePtr)
{
    std::string items[] = { "Customer 1", "Customer 2", "Customer 3", "Customer 4", "Customer 5", "Customer 6" };
    for (int i = 0; i < 6; i++)
    {
        bool success = queuePtr->enqueue(items[i]);
        if (!success)
            cout << "Failed to add " << items[i] << " to the queue." << std::endl;
        else if (success)
            cout << "Adding " << items[i] << std::endl;
    }
}

int main()
{
    QueueInterface<string>* queuePtr = new ArrayQueue<string>();
    
    cout << "Before inserting any values....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << "\n\n";
    cout << "Insering into queuePtr..." << endl;
    insertQueue(queuePtr);
    cout << "\nAfter inserting the values into queuePtr....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << endl;

    return 0;
}