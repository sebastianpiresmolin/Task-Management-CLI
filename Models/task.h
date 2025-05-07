

#ifndef TASKSTRUCT_H
#define TASKSTRUCT_H
#include <string>
#include <chrono>
#include <string>
#include <ctime>

using namespace std;

struct Task {
    int id;
    string title;
    time_t createdAt;
    string description;
    bool isDone;
    int deadline;

    Task(int id, const string& title, const string& description, int deadline)
        : id(id), title(title), description(description), deadline(deadline), isDone(false) {
        createdAt = std::time(nullptr);
    }

};



#endif //TASKSTRUCT_H
