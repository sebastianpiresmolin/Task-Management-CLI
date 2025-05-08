//
// Created by Sebastian Molin on 2025-05-08.
//

#include "exportTasks.h"

#include <filesystem>
#include <nlohmann/json_fwd.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <nlohmann/json.hpp>

#include "Models/task.h"

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
