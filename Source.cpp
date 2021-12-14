//Bola Ghaly
//Lab 5 - Banking Simulation using array-based implementation
#include "ArrayQueue.h"
#include <iostream>
#include <iomanip> //used for setprecision(2) for average wait time
#include <string>   
#include <cstdlib> //used for random number generator (1)
#include <ctime>   //used for random number generator (2)
using namespace std;

//Global Variables to be used in all of my functions -
string customers[] = { "Customer 1", "Customer 2", "Customer 3", "Customer 4", "Customer 5", "Customer 6" }; //6 Customers, 1 Teller
string transactionType[] = { "Check Deposit", "Cash Withdrawal", "Cash Deposit", "Check Balance" }; //4 Types of Transaction
int serviceTime[] = { 3, 2, 5, 1 }; //Service time for each type of transaction
int arrivalTime[6] = {}; //Arrival Time of each customer (randomly generated)
int departureTime[6] = {}; //Departure Time of each customer (depends on arrival time of each customer + their serivce time + their wait time)
int customersWaitTime[6] = {}; //Each customer's wait time (depends on arrival time of each customer + their serivce time + their departure time)

//Adds all customers to the queue using the "enqueue" in the QueueInterface file + their arrival time
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
                    cout << "09:0" << arrivalTime[i] << " AM and is waiting to be served!\n"; //09:0X
                }
                else if (arrivalTime[i] >= 10 && arrivalTime[i] <= 59) {
                    cout << "09:" << arrivalTime[i] << " AM and is waiting to be served!\n";  //09:XX
                }
                else if (arrivalTime[i] >= 60 && arrivalTime[i] <= 100) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n"; //10:0X
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";  //10:XX
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
                    cout << "09:0" << arrivalTime[i] << " AM and is waiting to be served!\n"; //09:0X
                }
                else if (arrivalTime[i] >= 10 && arrivalTime[i] <= 59) {
                    cout << "09:" << arrivalTime[i] << " AM and is waiting to be served!\n";  //09:XX
                }
                else if (arrivalTime[i] >= 60 && arrivalTime[i] <= 100) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n"; //10:0X
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";  //10:XX
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
                    cout << "09:0" << arrivalTime[i] << " AM and is waiting to be served!\n"; //09:0X
                }
                else if (arrivalTime[i] >= 10 && arrivalTime[i] <= 59) { 
                    cout << "09:" << arrivalTime[i] << " AM and is waiting to be served!\n"; //09:XX
                }
                else if (arrivalTime[i] >= 60 && arrivalTime[i] <= 100) {
                    if (arrivalTime[i] - 60 <= 9)
                        cout << "10:0" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n"; //10:0X
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << arrivalTime[i] - 60 << " AM and is waiting to be served!\n";  //10:XX
                }
            }
        }
    }
}

//Manages the Queue by -
//1- If Teller is free and someone is waiting then the customer at the front of the line moves to the teller.
//2- The service time is initialized (depending on a random transaction chosen by the random generator)
//and the customer’s total wait time can be determined.
//3- When the customer is done, they leave the bank (dequeue) and it output their depature time.
//4- Keeps running and checking until the queue is empty (peekFront).
void manageQueue(QueueInterface<string>* queuePtr) {
    for (int i = 0; i < 7; i++) {
        int randTransaction = (rand() % 4) + 0;
        if (i == 0) {
            cout << "--------------------------------------------------------------------------------\n";
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
                cout << "09:0" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n"; //09:0X
            }
            else if ((arrivalTime[i] + customersWaitTime[i]) >= 10 && (arrivalTime[i] + customersWaitTime[i]) <= 59) {
                cout << "09:" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";  //09:XX
            }
            else if ((arrivalTime[i] + customersWaitTime[i]) >= 60 && (arrivalTime[i] + customersWaitTime[i]) <= 100) {
                if (arrivalTime[i] - 60 <= 9)
                    cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n"; //10:0X
                else if (arrivalTime[i] - 60 <= 40)
                    cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";  //10:XX
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

            if (departureTime[i - 1] <= arrivalTime[i]) {
                customersWaitTime[i] = serviceTime[randTransaction];
                cout << customers[i] << "'s Total Wait Time: " << customersWaitTime[i] << " minute(s).\n";
                cout << customers[i] << " has left the bank at ";

                if ((arrivalTime[i] + customersWaitTime[i]) >= 1 && (arrivalTime[i] + customersWaitTime[i]) <= 9) {
                    cout << "09:0" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n"; //09:0X
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 10 && (arrivalTime[i] + customersWaitTime[i]) <= 59) {
                    cout << "09:" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n"; //09:XX
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 60 && (arrivalTime[i] + customersWaitTime[i]) <= 100) {
                    if (arrivalTime[i] - 60 <= 7)
                        cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n"; //10:0X
                    else if (arrivalTime[i] - 60 <= 40) 
                        cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";  //10:XX
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 101 && (arrivalTime[i] + customersWaitTime[i]) <= 119) {
                    if (arrivalTime[i] - 60 <= 7)
                        cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n"; //10:0X
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";  //10:XX
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 120) {
                    if (arrivalTime[i] - 120 <= 7)
                        cout << "11:0" << (arrivalTime[i] + customersWaitTime[i]) - 120 << " AM.\n"; //11:0X
                    else if (arrivalTime[i] - 120 <= 40)
                        cout << "11:" << (arrivalTime[i] + customersWaitTime[i]) - 120 << " AM.\n";  //11:XX
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
                    cout << "09:0" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n"; //09:0X
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 10 && (arrivalTime[i] + customersWaitTime[i]) <= 59) {
                    cout << "09:" << (arrivalTime[i] + customersWaitTime[i]) << " AM.\n";  //09:XX
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 60 && (arrivalTime[i] + customersWaitTime[i]) <= 100) {
                    if (arrivalTime[i] - 60 <= 7)
                        cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n"; //10:0X
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";  //10:XX
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 101 && (arrivalTime[i] + customersWaitTime[i]) <= 119) {
                    if (arrivalTime[i] - 60 <= 7)
                        cout << "10:0" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n"; //10:0X
                    else if (arrivalTime[i] - 60 <= 40)
                        cout << "10:" << (arrivalTime[i] + customersWaitTime[i]) - 60 << " AM.\n";  //10:XX
                }
                else if ((arrivalTime[i] + customersWaitTime[i]) >= 120) {
                    if (arrivalTime[i] - 120 <= 7)
                        cout << "11:0" << (arrivalTime[i] + customersWaitTime[i]) - 120 << " AM.\n"; //11:0X
                    else if (arrivalTime[i] - 120 <= 40)
                        cout << "11:" << (arrivalTime[i] + customersWaitTime[i]) - 120 << " AM.\n";  //11:XX
                }
                queuePtr->dequeue();
            }
            cout << "--------------------------------------------------------------------------------\n";
        }
    }
}

int main()
{
    QueueInterface<string>* queuePtr = new ArrayQueue<string>();
    
    //Intro
    cout << "\t\t\t\t\t   CSC326 Lab 5 - Banking Simulation\n";
    cout << "\t\t\t\t\t       The Time Now is 09:00 AM\n";
    cout << "\t\t----------------------------------------------------------------------------------------\n";

    //Menu of the transaction types + their service time
    cout << "Transaction Types:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << "- " << transactionType[i] << ", Expected Service Time: " << serviceTime[i] << " minute(s)." << "\n";
    }
    cout << endl;

    cout << "Tellers = 1\n\n"; //This "bank" (program) has just one teller.

    cout << "Before inserting any values....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << "\n\n"; //SHOULD BE TRUE - IS EMPTY
    insertQueue(queuePtr); //Function call
    cout << "\nAfter inserting the values into queuePtr....\n" << boolalpha; //displays "true" or "false" instead of "1" or "0"
    cout << "Is the queue empty? " << queuePtr->isEmpty() << endl;  //SHOULD BE FALSE - IS NOT EMPTY

    cout << "\nManaging the queue:\n";
    manageQueue(queuePtr); //Function call

    //This for-loop calculates the average wait time of all customers. (average time of each customer added together / total number of customers in the queue).
    double avgWaitTime = 0;
    for (int i = 0; i < 6; i++) {
        avgWaitTime += customersWaitTime[i];
    }
    avgWaitTime = avgWaitTime / 6;
    cout << "\nThe average wait time - " << fixed << setprecision(2) << avgWaitTime << " minutes.\n\n";

    return 0;
}