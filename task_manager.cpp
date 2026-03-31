#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "helper_functions.cpp"



int main() {
    std::string filename = "task-lists/tl1.txt";
    std::vector <Task> tasks;
    int choice;
    
    LoadTasks(tasks, filename);
    
    
    while(true){
        
        printOptions();
        
        std::cin >> choice;
        std::string desc;
        
        switch (choice){
            case 1:
            std::cout << "Enter task: ";
            std::cin.ignore();
            std::getline(std::cin, desc);
            tasks.push_back({(int) tasks.size(), desc, false});
            std::cout << "\n";
            break;
            
            case 2:
            std::cout << "\n";
            std::cout << "Task List";
            std::cout << "\n";
            for(int i = 0; i < tasks.size(); i++)
            {
                std::cout << tasks[i].id << ". ";
                if(tasks[i].completed) std::cout << "✓";
                else std::cout << " ";
                std::cout << tasks[i].description << "\n";
            }
            std::cout << "\n";
            break;
            
            //to save vector <Task> tasks
            //to save time I just decided to hardcode the save file directory, but in the future might add option to have multiple lists
            case 3:{
            /*
            std::cout<< "Task List Name: ";
            std::cin.ignore();
            std::getline(std::cin, desc);
            std::string filename = "task-lists/" + desc + ".txt";
            std::ofstream file(filename);
            
            for(const Task t : tasks)
            {
                file << t.id << "|" << t.description << "|" << t.completed << "\n";
                }
                file.close();
                break;
                */

               std::ofstream file(filename);
               for(const Task t : tasks)
                {
                    file << t.id << "|" << t.description << "|" << t.completed << "\n";
                }
                file.close();
                break;

            }

            //For marking a task as completed
            case 4:{

                int taskID;
                std::string tempstr;
                std::cout << "Completed task: "; 
                std::cin.ignore();  //to ingnore selection input error
                std::getline(std::cin, tempstr);
                taskID = std::stoi(tempstr);

                tasks[taskID].completed = true;
                break;
            }
            case 5:
                tasks.clear();
                break;
                
            default:
                return 0;
        }

        
    }




    return 0;
}

