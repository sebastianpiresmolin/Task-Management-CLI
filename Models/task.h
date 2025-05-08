

#ifndef TASKSTRUCT_H
#define TASKSTRUCT_H
#include <string>
#include <ctime>


using namespace std;



struct Task {
    int id;
    std::string title;
    time_t createdAt;
    std::string description;
    bool isDone;
    int deadline;

    // Default constructor for JSON import
    Task() = default;

    // Existing constructor for new task creation
    Task(int id, const std::string& title, const std::string& description, int deadline)
        : id(id), title(title), description(description), deadline(deadline),
          isDone(false), createdAt(std::time(nullptr)) {}
};



#endif //TASKSTRUCT_H
