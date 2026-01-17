// to-do-list_CLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <string>
#include <vector>
using namespace std;

vector<string>tasks;
void addTask(string task);

int main(){
    cout <<  "Please enter a number to perform a task:\n 1. Add Task \n 2. View Task \n 3. Mark task as done \n 4. Delete Task \n 5. Exit \n\n";
    int number{};
    cin >> number;

    //switch (number) {

    //case 1:
    //    cin >> task;
    //    addTask(task);
    //    break;
    //case 2:

    //    break;
    //case 3:

    //    break;
    //case 4:

    //    break;
    //default:
    //    cout << 'hmm';
    //}

   if (number == 1) {
       cout << "Enter the task \n";
       string task;
       cin >> task;
       addTask(task);
   }
    return 0;
}

void addTask(string task) {
    tasks.push_back(task);
    cout << "You have successfully added a task";
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
