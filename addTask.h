//
// Created by sebastian.molin on 2025-05-07.
//

#ifndef ADDTASK_H
#define ADDTASK_H

void AddTask(std::vector<Task>& taskList) {
    int id = taskList.size();
    Task task = {id, "TestTitle", "TestDesc", 1};

    cout << "# Add Task #" << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter task title: ";
    getline(std::cin, task.title);


    cout << "\nEnter task description: ";
    getline(std::cin, task.description);


    cout << "\nEnter days until deadline: ";
    cin >> task.deadline;

    taskList.push_back(task);

    cout << "Task added!" << endl;

}

#endif //ADDTASK_H
