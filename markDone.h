//
// Created by sebastian.molin on 2025-05-07.
//

#ifndef MARKASDONE_H
#define MARKASDONE_H
void MarkDone(vector<Task>& taskList) {
    int id;

    cout << "# Mark task as done #" << endl;
    cout << "Enter task id to set as done: ";
    cin >> id;

    if (id >= 0 && id < taskList.size()) {
        taskList[id].isDone = true;
        cout << "Task with id: " << taskList[id].id << " and title: " << taskList[id].title << ", marked as done." << endl;
    } else {
        cout << "Invalid task ID." << endl;
    }
}
#endif //MARKASDONE_H
