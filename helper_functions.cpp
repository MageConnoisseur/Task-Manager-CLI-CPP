#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

struct Task{
    int id;
    std::string description;
    bool completed;
};

void printOptions (){
    std::vector <std::string> optionsList = {
        "1. Add Tasks",
        "2. View Tasks",
        "3. Save List",
        "4. Complete Task",
        "5. Reset Task List",
        "6. Exit"
    };
    std::cout << "\n";
    for(int i = 0; i < optionsList.size(); i++)
    {
        std::cout << optionsList[i] << "\n";
    }

}

void LoadTasks(std::vector <Task> &tasks, const std::string filename){
    std::ifstream file (filename);

    std::string line;

    Task t;

    //Because of how I intially saved the task vectors, I am using '|' as a delemiter, except for when chcking for the completed boolean
    //we use the deafule '\\n' as the delemter for that becasue in the save for readiblity I chose to do a new line between vector <Task>s
    while (std::getline(file, line, '|'))
    {
        t.id = std::stoi(line);

        std::getline(file, t.description, '|');

        std::getline(file, line);
        t.completed = (line == "1");

        tasks.push_back(t);
    }
}