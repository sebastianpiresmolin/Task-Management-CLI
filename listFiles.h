//
// Created by sebastian.molin on 2025-05-07.
//

#ifndef LISTFILES_H
#define LISTFILES_H

void ListTasks(const std::vector<Task>& taskList) {
    if (taskList.empty()) {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    for (const Task& task : taskList) {
        std::cout << "ID: " << task.id << std::endl;
        std::cout << "Title: " << task.title << std::endl;
        std::cout << "Description: " << task.description << std::endl;

        std::tm* timeinfo = std::localtime(&task.createdAt);
        std::cout << "Created At: " << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S") << std::endl;

        time_t deadlineTime = task.createdAt + (task.deadline * 24 * 60 * 60);
        tm* deadlineInfo = std::localtime(&deadlineTime);
        std::cout << "Deadline: " << std::put_time(deadlineInfo, "%Y-%m-%d") << std::endl;
        std::cout << "Done: " << (task.isDone ? "Yes" : "No") << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

#endif //LISTFILES_H
