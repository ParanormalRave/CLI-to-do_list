// to_do-list_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

vector<string>tasks;
ofstream taskfile("tasksfile.txt");
int num{};
void addTask(string task);
void viewTask();
void markDone();
void del(int delet);

int main() {
    cout << "Please enter a number to perform a task:\n 1. Add Task \n 2. View Task \n 3. Mark task as done \n 4. Delete Task \n 5. Exit \n\n";
    int number{};
    cin >> number;

    do {
        if (number == 1) {
            string task;
            do {
                cout << "Enter the task\n Or Enter exit to quit adding tasks\n";
                cin >> task;
                taskfile << task;
                //getline(cin,task);
                addTask(task);
            } while ((task) != "exit");
            cout << "Enter 5 to exit operation";
        }
        else if (number == 2) {
            int view{};
            cin >> view;
            viewTask();
            taskfile << view;
        }
        else if (number == 3) {
            markDone();
        }
        else if (number == 4) {
            cout << "Enter the task you wish to delete ";
            int deleteTask{};
            cin >> deleteTask;
            del(deleteTask);
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
    cout << "\033[33mYay\033[0m\n";
}

void viewTask() {

    cout << format("{:>5} {:>10}\n", "No.", "Task");
    for (int i{}; i < tasks.size()-1; i++) {
        cout << format("{:>5} {:>10}\n", i + 1, tasks[i]);
    }
}

void markDone() {
    bool isMarked{};
    cout << "Enter the index number of the task you want wish to mark\n ";
    cout << format("{:>5} {:>10} {:>15}\n", "No.", "Task", "Marked");
    for (int i{}; i < tasks.size()-1; i++) {
        cout << format("{:>5} {:>10} {:>15}\n", i + 1, tasks[i], isMarked);
    }
    cin >> num;
    if (num <= 0 or num > tasks.size()) {
        cout << format("Enter the a number between 1 to {}", tasks.size()) ;
    }
    else {
        cout << format("{:>5} {:>10} {:>15}\n", "No.", "Task", "Marked");
        for (int i{}; i < tasks.size() - 1; i++) {
            if (i == num - 1) {
                isMarked = true;
            }
            else {
                isMarked = false;
            }
            cout << format("{:>5} {:>10} {:>15}\n", i + 1, tasks[i], isMarked);
            taskfile << format("{:>5} {:>10} {:>15}\n", i + 1, tasks[i], isMarked);
            taskfile.close();
        }
    }
}

void del(int delet) {
    viewTask();
    tasks.erase(tasks.begin() + delet-1);
    viewTask();

}
