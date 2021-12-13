//Bola Ghaly
//Lab 5 - Banking Simulation using array-based implementation
#include "ArrayQueue.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string customers[] = { "Customer 1", "Customer 2", "Customer 3", "Customer 4", "Customer 5", "Customer 6" };
string transactionType[] = { "Check Deposit", "Cash Withdrawal", "Cash Deposit", "Check Balance" };
int serviceTime[] = { 3, 2, 5, 1 };
int arrivalTime[6] = {};
int departureTime[6] = {};

void insertQueue(QueueInterface<string>* queuePtr) {
    srand(time(0));  // Initialize random number generator.
    int randNum = (rand() % 59) + 1;

    for (int i = 0; i < 6; i++)
    {
        bool success = queuePtr->enqueue(customers[i]);
        if (i == 0) {
            arrivalTime[i] = randNum;
            if (!success)
                cout << "Failed to add " << customers[i] << " to the queue." << endl;
            else if (success) {
                cout << customers[i] << " has arrived at ";
                if (arrivalTime[i] >= 1 && arrivalTime[i] <= 9) {
                    cout << "09:0" << arrivalTime[i] << " AM and is waiting to be served!\n";
                }
                else if (arrivalTime[i] >= 10 && arrivalTime[i] <= 59) {
                    cout << "09:" << arrivalTime[i] << " AM and is waiting to be served!\n";
                }
                else if (arrivalTime[i] >= 60 && arrivalTime[i] <= 100) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";
                }
            }
        }
        else if (i > 0 && (arrivalTime[i - 1] != 100)) {
            while (randNum <= arrivalTime[i - 1]) {
                randNum = (rand() % 100) + 1;
                arrivalTime[i] = randNum;
            }
            if (!success)
                cout << "Failed to add " << customers[i] << " to the queue." << endl;
            else if (success) {
                cout << customers[i] << " has arrived at ";
                if (arrivalTime[i] >= 1 && arrivalTime[i] <= 9) {
                    cout << "09:0" << arrivalTime[i] << " AM and is waiting to be served!\n";
                }
                else if (arrivalTime[i] >= 10 && arrivalTime[i] <= 59) {
                    cout << "09:" << arrivalTime[i] << " AM and is waiting to be served!\n";
                }
                else if (arrivalTime[i] >= 60 && arrivalTime[i] <= 100) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";
                }
            }
        }
        else if (i > 0 && (arrivalTime[i - 1] == 100)) {
            arrivalTime[i] = randNum;
            if (!success)
                cout << "Failed to add " << customers[i] << " to the queue." << endl;
            else if (success) {
                cout << customers[i] << " has arrived at ";
                if (arrivalTime[i] >= 1 && arrivalTime[i] <= 9) {
                    cout << "09:0" << arrivalTime[i] << " AM and is waiting to be served!\n";
                }
                else if (arrivalTime[i] >= 10 && arrivalTime[i] <= 59) {
                    cout << "09:" << arrivalTime[i] << " AM and is waiting to be served!\n";
                }
                else if (arrivalTime[i] >= 60 && arrivalTime[i] <= 100) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";
                }
            }
        }
    }
}

void manageQueue(QueueInterface<string>* queuePtr) {
    int customersWaitTime[6] = {};

    for (int i = 0; i < 7; i++) {
        int randTransaction = (rand() % 3) + 0;
        if (i == 0) {
            cout << "----------------------------------------------------------------------------\n";
            try
            {
                cout << "peekFront: " << queuePtr->peekFront() << endl;
            }
            catch (PrecondViolatedExcep e)
            {
                cout << e.what() << endl;
                break;
            }  // end try/catch
            cout << customers[i] << " has chosen " << transactionType[randTransaction] << ", Expected Service Time: " << serviceTime[randTransaction] << " minute(s).\n";
            customersWaitTime[i] = serviceTime[randTransaction];
            cout << customers[i] << "'s Total Wait Time: " << customersWaitTime[i] << " minute(s).\n";
            cout << customers[i] << " has left the bank at ";

            if ((arrivalTime[i] + customersWaitTime[i]) >= 1 && (arrivalTime[i] + customersWaitTime[i]) <= 9) {
                cout << "09:0" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";
            }
            else if ((arrivalTime[i] + customersWaitTime[i]) >= 10 && (arrivalTime[i] + customersWaitTime[i]) <= 59) {
                cout << "09:" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";
            }
            else if ((arrivalTime[i] + customersWaitTime[i]) >= 60 && (arrivalTime[i] + customersWaitTime[i]) <= 100) {
                if (arrivalTime[i] - 60 <= 9)
                    cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
                else if (arrivalTime[i] - 60 <= 40)
                    cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
            }
            departureTime[i] = (arrivalTime[i] + customersWaitTime[i]);
            queuePtr->dequeue();
            cout << "--------------------------------------------------------------------------------\n";
        }
        else if (i > 0) {
            try
            {
                cout << "peekFront: " << queuePtr->peekFront() << endl;
            }
            catch (PrecondViolatedExcep e)
            {
                cout << e.what() << endl;
                break;
            }  // end try/catch

            cout << customers[i] << " has chosen " << transactionType[randTransaction] << ", Expected Service Time: " << serviceTime[randTransaction] << " minute(s).\n";


            if (arrivalTime[i] >= departureTime[i - 1]) {
                customersWaitTime[i] = serviceTime[randTransaction];
                cout << customers[i] << "'s Total Wait Time: " << customersWaitTime[i] << " minute(s).\n";
                cout << customers[i] << " has left the bank at ";

                if ((arrivalTime[i] + customersWaitTime[i]) >= 1 && (arrivalTime[i] + customersWaitTime[i]) <= 9) {
                    cout << "09:0" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 10 && (arrivalTime[i] + customersWaitTime[i]) <= 59) {
                    cout << "09:" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 60 && (arrivalTime[i] + customersWaitTime[i]) <= 100) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
                }
                departureTime[i] = (arrivalTime[i] + customersWaitTime[i]);
                queuePtr->dequeue();
            }
            else if (arrivalTime[i] < departureTime[i - 1]) {
                int tempNum = (departureTime[i - 1] - arrivalTime[i]) + serviceTime[randTransaction];
                departureTime[i] = arrivalTime[i] + tempNum;

                customersWaitTime[i] = tempNum;
                cout << customers[i] << "'s Total Wait Time: " << customersWaitTime[i] << " minute(s).\n";
                cout << customers[i] << " has left the bank at ";

                if ((arrivalTime[i] + customersWaitTime[i]) >= 1 && (arrivalTime[i] + customersWaitTime[i]) <= 9) {
                    cout << "09:0" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 10 && (arrivalTime[i] + customersWaitTime[i]) <= 59) {
                    cout << "09:" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 60 && (arrivalTime[i] + customersWaitTime[i]) <= 99) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 100 && (arrivalTime[i]+customersWaitTime[i]) <= 119) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";
                }




                departureTime[i] = (arrivalTime[i] + customersWaitTime[i]);
                queuePtr->dequeue();
            }
            cout << "--------------------------------------------------------------------------------\n";
        }
    }
}

int main()
{
    QueueInterface<string>* queuePtr = new ArrayQueue<string>();
    
    cout << "\t\t\t\t\t   CSC326 Lab 5 - Banking Simulation\n";
    cout << "\t\t\t\t\t       The Time Now is 09:00 AM\n";
    cout << "\t\t----------------------------------------------------------------------------------------\n\n";

    cout << "Transaction Types:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << "- " << transactionType[i] << ", Expected Service Time: " << serviceTime[i] << " minute(s)." << "\n";
    }
    cout << endl;

    cout << "Before inserting any values....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << "\n\n";

    insertQueue(queuePtr);

    cout << "\nAfter inserting the values into queuePtr....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << endl;


    cout << "\nManaging the queue:\n";
    manageQueue(queuePtr);


    return 0;
}