#include <iostream>
#include <fstream>
#include "menu.h"
#include <string>
#include <vector>
#include "Models/task.h"
#include <iomanip>
#include <chrono>
#include "listFiles.h"
#include "addTask.h"
#include "seedTask.h"
#include "markDone.h"
#include "nlohmann/json.hpp"

using namespace std;

vector<Task> taskList;

void ExportTasks(const std::vector<Task>& taskList) {
    nlohmann::json tasksJson;

    for (const Task& task : taskList) {
        nlohmann::json taskJson;

        taskJson["id"] = task.id;
        taskJson["title"] = task.title;
        taskJson["description"] = task.description;
        taskJson["isDone"] = task.isDone;

        std::tm* timeinfo = std::localtime(&task.createdAt);
        std::ostringstream createdAtStream;
        createdAtStream << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
        taskJson["createdAt"] = createdAtStream.str();

        time_t deadlineTime = task.createdAt + (task.deadline * 24 * 60 * 60);
        std::tm* deadlineInfo = std::localtime(&deadlineTime);
        std::ostringstream deadlineStream;
        deadlineStream << std::put_time(deadlineInfo, "%Y-%m-%d");
        taskJson["deadline"] = deadlineStream.str();

        tasksJson.push_back(taskJson);
    }

    std::cout << "Writing to: " << std::filesystem::absolute("tasks.json") << std::endl;
    std::ofstream outFile("tasks.json");
    outFile << std::setw(4) << tasksJson << std::endl;

    std::cout << "Tasks written to tasks.json" << std::endl;
}


void Menu() {
    int choice = -1;
    SeedTask(taskList);

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
                cout << "Trigger 5\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}