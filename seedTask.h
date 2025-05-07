//
// Created by sebastian.molin on 2025-05-07.
//

#ifndef SEEDTASK_H
#define SEEDTASK_H
void SeedTask(std::vector<Task>& taskList) {
    Task task = {0, "Seed", "Seed", 1};
    taskList.push_back(task);
}
#endif //SEEDTASK_H
