#include <iostream>
#include <vector>
#include <sstream>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;

enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

ostream& operator <<(ostream& out, const TaskStatus& status) {
    string statusName;
    switch (status) {
        case TaskStatus::NEW:
            statusName = "\"NEW\"";
            break;
        case TaskStatus::IN_PROGRESS:
            statusName = "\"IN_PROGRESS\"";
            break;
        case TaskStatus::TESTING:
            statusName = "\"TESTING\"";
            break;
        case TaskStatus::DONE:
            statusName = "\"DONE\"";
            break;
    }
    return out << statusName;
}

TasksInfo operator-(const TasksInfo& lhs, const TasksInfo& rhs){
			TasksInfo t;
			for(auto i:lhs){
					if(i.second!=0){
						if(rhs.count(static_cast<TaskStatus>(i.first))>=1){
							i.second -=rhs.at(static_cast<TaskStatus>(i.first));
							if(i.second!=0){t[static_cast<TaskStatus>(i.first)] =i.second;}
						}else{
							t[static_cast<TaskStatus>(i.first)] =i.second;
						}
				}
			}


			return t;
		}


class TeamTasks {
	public:
		  // Получить статистику по статусам задач конкретного разработчика
	const TasksInfo&  GetPersonTasksInfo(const string& person) const{
			  	  return team.at(person);
		  }

		  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
		  void AddNewTask(const string& person){
			   ++team[person][TaskStatus::NEW];
			//  cout <<" person = " << person << " info status (number of status) = " << team[person][TaskStatus::NEW] << endl;

		  }
		  // Обновить статусы по данному количеству задач конкретного разработчика,
		  // подробности см. ниже
 tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
	 	 	 	 	 	 	 	TasksInfo task_update;
	 	 	 	 	 	 	 	int temp_task_count= task_count;
	 	 	 	 	 	 	 	for(auto& i: team[person]){
	 	 	 	 	 	 	 		if(task_count<i.second){
	 	 	 	 	 	 	 			int n;
	 	 	 	 	 	 	 			 n = static_cast<int>( i.first);
	 	 	 	 	 	 	 			task_update[static_cast<TaskStatus>(n+1)]=i.second;
	 	 	 	 	 	 	 		}else if (task_count>i.second){
	 	 	 	 	 	 	 			task_count-=i.second;
	 	 	 	 	 	 	 	}
	 	 	 	 	 	 	 	}
	 	 	 	 	 	 	 	if(task_count!=0){
	 	 	 	 	 	 	 	task_update[static_cast<TaskStatus>(team[person].size())]=task_count;
	 	 	 	 	 	 	 	}
	 	 	 	 	 	 	 	// save new team tasks for person
								int index_key_status = 0;
								int value_for_next_status =0;
								for(auto& i: team[person]){
									 if(temp_task_count> i.second){
											value_for_next_status = i.second;
											temp_task_count-= i.second;
											i.second = 0;
									  }else if(temp_task_count <= i.second){
										  i.second +=value_for_next_status;
										  i.second-=temp_task_count;
										  value_for_next_status =temp_task_count;

									  }
		 	 	 	 	 	 		 ++ index_key_status;
		 	 	 	 	 	  	 }
		 	 	 	 	 	 	team[person][static_cast<TaskStatus>(index_key_status)]= value_for_next_status;
		 	 	 	 	 	 	TasksInfo t = team[person]- task_update;

	 	 	 	 	 	 	 return {task_update, team[person]};
 	 	 	 	 			}
	private:
		   map<string, TasksInfo> team;
		  };

template <typename Collection>
string Join(const Collection& c, const string& d) {
    stringstream ss;
    bool isFirst = true;
    for (const auto& i : c) {
        if(!isFirst) {
            ss << d;
        }
        isFirst = false;
        ss << i;
    }
    return ss.str();
}
template <typename F, typename S>
ostream& operator <<(ostream& out, const pair<F,S>& p) {
    return out << p.first << ": " << p.second;
}
template <typename K, typename V>
ostream& operator <<(ostream& out, const map<K,V>& m){
    return out << '{' << Join(m, ", ") << '}';
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
   return out << '['  << Join(v, ", ") << ']';
}
int main() {
    TeamTasks tasks;

    while(cin) {
        string command, person;
        int num;
        cin >> command >> person;
        if (command == "AddNewTasks") {
            cin >> num;
            while (num--)
                tasks.AddNewTask(person);
            cout << "[]" << endl;
        } else if (command == "PerformPersonTasks") {
            cin >> num;

            TasksInfo updated_tasks, untouched_tasks;

           // string person ="Alice";
            //int num = 5;
           // for(int i=0; i<5; ++i)
           // tasks.AddNewTask(person);

            		tie(updated_tasks, untouched_tasks) =
                    tasks.PerformPersonTasks(person, num);

            cout << vector<TasksInfo>{updated_tasks, untouched_tasks } << endl;

        } else if (command == "GetPersonTasksInfo") {
            cout << tasks.GetPersonTasksInfo(person) << endl;
        } else if (command.size() && command[0] != '#'){
            throw invalid_argument("wrong command: " + command);
        }
    }

}
