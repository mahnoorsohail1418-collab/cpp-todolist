#include<iostream>
#include<string>
using namespace std;

// Number of tasks allowed
const int maxtasks=100;

// Task class
class task{
protected:
    string title;
    string category;
    bool completed;
public:
    task(string t,string c){
        title=t;
        category=c;
        completed=false;
    }
    void markdone(){ completed=true; }
    virtual void showtask(){
        cout << (completed ? "[./]" : "[X]") << " ";
        cout << "Title: " << title << " - Category: " << category << endl;
    }
};

// Task with deadline
class deadlinetask:public task{
private:
    string deadline;
public:
    deadlinetask(string t,string c,string d):task(t,c){ deadline=d; }
    void showtask(){
        cout << (completed ? "[./]" : "[X]") << " ";
        cout << "Title: " << title << " - Category: " << category << " - Deadline: " << deadline << endl;
    }
};

// Task with priority
class prioritytask:public task{
private:
    string priority;
public:
    prioritytask(string t,string c,string p):task(t,c){ priority=p; }
    void showtask(){
        cout << (completed ? "[./]" : "[X]") << " ";
        cout << "Title: " << title << " - Category: " << category << " - Priority: " << priority << endl;
    }
};

// Todo list
class todolist{
private:
    task* tasks[maxtasks];
    int count;
public:
    todolist(){ count=0; }
    void addtask(task* t){
        if(count<maxtasks){
            tasks[count++]=t;
        } else { cout << "Task list is full!" << endl; }
    }
    void showall(){
        if(count==0){ cout<<"No tasks yet"<<endl; return; }
        cout<<"\nTODOLIST\n";
        for(int i=0;i<count;i++){
            cout<<i+1<<". ";
            tasks[i]->showtask();
        }
    }
    void taskdone(int index){
        if(index>=1 && index<=count){
            tasks[index-1]->markdone();
            cout<<"Task marked as done"<<endl;
        } else { cout<<"Invalid task number"<<endl; }
    }
    ~todolist(){
        for(int i=0;i<count;i++) delete tasks[i];
    }
};

// Main function
int main(){
    todolist todo;
    int choice;
    do{
        cout<<"\nTODO LIST MENU"<<endl;
        cout<<"1.Add Normal Task"<<endl;
        cout<<"2.Add Task with Deadline"<<endl;
        cout<<"3.Add Task with Priority"<<endl;
        cout<<"4.Show all Tasks"<<endl;
        cout<<"5.Mark a Task Done"<<endl;
        cout<<"6.EXIT"<<endl;
        cout<<"ENTER CHOICE: ";
        cin>>choice;

        if(choice==1){
            string title,category;
            cout<<"Enter task title: "; cin.ignore(); getline(cin,title);
            cout<<"Enter task category: "; getline(cin,category);
            todo.addtask(new task(title,category));
        }
        else if(choice==2){
            string title,category,deadline;
            cout<<"Enter task title: "; cin.ignore(); getline(cin,title);
            cout<<"Enter task category: "; getline(cin,category);
            cout<<"Enter task deadline: "; getline(cin,deadline);
            todo.addtask(new deadlinetask(title,category,deadline));
        }
        else if(choice==3){
            string title,category,priority;
            cout<<"Enter task title: "; cin.ignore(); getline(cin,title);
            cout<<"Enter task category: "; getline(cin,category);
            cout<<"Enter task priority (1.HIGH 2.MEDIUM 3.LOW): "; cin>>priority;
            todo.addtask(new prioritytask(title,category,priority));
        }
        else if(choice==4) todo.showall();
        else if(choice==5){
            int index;
            cout<<"Enter task number to mark as done: "; cin>>index;
            todo.taskdone(index);
        }
    } while(choice!=6);

    cout<<"GOODBYE!"<<endl;
    return 0;
}
