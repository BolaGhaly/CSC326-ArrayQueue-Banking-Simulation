//Bola Ghaly
//Lab 5 - Banking Simulation using array-based implementation
#include "ArrayQueue.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string transactionType[] = { "Check Deposit", "Cash Withdrawal", "Cash Deposit", "Check Balance" };
int serviceTime[] = { 3, 2, 5, 1 };

void insertQueue(QueueInterface<string>* queuePtr)
{
    srand((unsigned)time(0));

    cout << "Transaction Types:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << "- " << transactionType[i] << ", Expected Service Time: " << serviceTime[i] << " minute(s)." << "\n";
    }
    cout << endl;

    cout << "Inserting into queuePtr..." << endl;
    string items[] = { "Customer 1", "Customer 2", "Customer 3", "Customer 4", "Customer 5", "Customer 6" };
    for (int i = 0; i < 6; i++)
    {
        bool success = queuePtr->enqueue(items[i]);
        if (!success)
            cout << "Failed to add " << items[i] << " to the queue." << endl;
        else if (success)
            cout << items[i] << " has arrived and is waiting to be served!" << endl;
    }
}

void manageQueue(QueueInterface<string>* queuePtr) {
    
}


int main()
{
    QueueInterface<string>* queuePtr = new ArrayQueue<string>();
    
    cout << "Before inserting any values....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << "\n\n";
    insertQueue(queuePtr);
    cout << "\nAfter inserting the values into queuePtr....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << endl;

    return 0;
}