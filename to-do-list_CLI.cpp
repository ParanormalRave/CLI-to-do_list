// to-do-list_CLI.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <format>
#include <vector>
#include <cctype>
using namespace std;

vector<string>tasks;
void addTask(string task);
void viewTask();
void markDone();

int main(){
    cout <<  "Please enter a number to perform a task:\n 1. Add Task \n 2. View Task \n 3. Mark task as done \n 4. Delete Task \n 5. Exit \n\n";
    int number{};
    cin >> number;
    
    do {
        if (number == 1) {
            string task;
            do {
                cout << "Enter the task\n Or Enter exit to quit adding tasks\n";
                cin >> task;
                addTask(task);
            } while ((task) != "exit");
            cout << "Enter 5 to exit operation";
        }else if(number == 2){
            int view{};
            cin >> view;
            viewTask();
        }
        else if (number == 3) {
            markDone();
        }
        cin >> number;
    } while (number != 5);
    
    return 0;
}

void addTask(string task) {
    if (task == "exit") {
        cout << "You have successfully added tasks";
    }
    tasks.push_back(task);
    cout << "You have successfully added a task\n";
}

void viewTask() {
    cout << format("{:>5} {:>10}\n", "No.", "Task");
    for (int i{0}; i < tasks.size(); i++) {
        cout << format("{:>5} {:>10}\n", i+1, tasks[i] );
    }
}

void markDone() {

}
// Run program: Ctrl + F5 or Debug > S
// Tips for Getting Started: 
//   1. Use the Solution Explorer window ttart Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
