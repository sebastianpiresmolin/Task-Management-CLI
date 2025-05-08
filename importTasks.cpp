//
// Created by Sebastian Molin on 2025-05-08.
//

#include "importTasks.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#include "Models/task.h"


void ImportTasks(std::vector<Task>& taskList) {
    std::ifstream inFile("tasks.json");
    if (!inFile.is_open()) {
        std::cerr << "Error opening tasks.json for reading." << std::endl;
        return;
    }

    nlohmann::json tasksJson;
    try {
        inFile >> tasksJson;
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return;
    }

    int initalSize = taskList.size();
    int importedCount = 0;

    for (const auto& taskJson : tasksJson) {
        Task task{};

        int id = taskList.size();

        task.id = id;
        task.title = taskJson["title"];
        task.description = taskJson["description"];
        task.isDone = taskJson["isDone"];

        std::tm tmCreatedAt = {};
        std::string str = taskJson["createdAt"].get<std::string>();
        std::istringstream ssCreatedAt(str);
        ssCreatedAt >> std::get_time(&tmCreatedAt, "%Y-%m-%d %H:%M:%S");
        task.createdAt = ssCreatedAt.fail() ? std::time(nullptr) : std::mktime(&tmCreatedAt);

        std::tm tmDeadline = {};
        std::string deadlineStr = taskJson["deadline"].get<std::string>();
        std::istringstream ssDeadline(deadlineStr);
        ssDeadline >> std::get_time(&tmDeadline, "%Y-%m-%d");
        tmDeadline.tm_hour = 12;

        time_t deadlineTime = ssDeadline.fail()
            ? task.createdAt + (7 * 24 * 60 * 60)
            : std::mktime(&tmDeadline);

        task.deadline = static_cast<int>((deadlineTime - task.createdAt) / (24 * 60 * 60));

        taskList.push_back(task);
        importedCount++;
    }

    std::cout << "Successfully imported " << importedCount
              << " tasks from tasks.json" << std::endl;
}