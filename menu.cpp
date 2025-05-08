#include <iostream>
#include <fstream>
#include "menu.h"
#include <vector>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

#include "Models/task.h"
#include "listFiles.h"
#include "addTask.h"
#include "exportTasks.h"
#include "importTasks.h"
#include "markDone.h"

using namespace std;

vector<Task> taskList;

void Menu() {
    int choice = -1;

    while (true) {
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "| 1. Add new task | 2. List tasks | 3. Mark a task as done | 4. Export as JSON | 5. Import from JSON | 0. Exit program |" << endl;
        cout << "Select an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                AddTask(taskList);
                break;
            case 2:
                ListTasks(taskList);
                break;
            case 3:
                MarkDone(taskList);
                break;
            case 4:
                ExportTasks(taskList);
                break;
            case 5:
                ImportTasks(taskList);
                break;
            case 0:
                cout << "Exiting program.\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}