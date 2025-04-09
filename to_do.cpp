#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ToDoList
{
    vector<pair<string, bool>> list;

public:
    void addList();
    void displayList();
    void deleteAll();
    void deleteComp();
    void markComplete();
};

void ToDoList::addList()
{
    pair<string, bool> task;
    cin.ignore();
    cout << "Enter task: ";
    getline(cin, task.first);
    task.second = false;

    list.push_back(task);
    cout << "Task added.\n";
}

void ToDoList::displayList()
{
    if (list.empty())
    {
        cout << "No tasks to display.\n";
        return;
    }

    int i = 0;
    for (const auto& t : list)
    {
        cout << i << ". " << t.first << endl;
        cout << "   Status: ";
        t.second ? cout << "Completed" : cout << "Pending";
        cout << "\n\n";
        ++i;
    }
}

void ToDoList::deleteAll()
{
    cout << "Delete All Tasks? (Y/N): ";
    char c;
    cin >> c;

    if (c == 'Y' || c == 'y')
        list.clear();

    cout << "All tasks deleted.\n";
}

void ToDoList::deleteComp()
{
    for (auto it = list.begin(); it != list.end(); )
    {
        if (it->second)
            it = list.erase(it);
        else
            ++it;
    }
    cout << "Completed tasks deleted.\n";
}

void ToDoList::markComplete()
{
    int idx;
    cout << "Enter the task number to mark as complete: ";
    cin >> idx;

    if (idx >= 0 && idx < list.size())
        list[idx].second = true;
    else
        cout << "Invalid index.\n";
}

int main()
{
    ToDoList todo;
    int choice;

    do
    {
        cout << "\n==== TO-DO LIST MENU ====\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Completed Tasks\n";
        cout << "5. Delete All Tasks\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                todo.addList();
                break;
            case 2:
                todo.displayList();
                break;
            case 3:
                todo.markComplete();
                break;
            case 4:
                todo.deleteComp();
                break;
            case 5:
                todo.deleteAll();
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    while (choice != 6);

    return 0;
}
