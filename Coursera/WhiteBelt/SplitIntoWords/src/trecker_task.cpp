
#include <iostream>
#include <vector>
#include <sstream>
#include <tuple>
#include <map>



using namespace std;

enum class TaskStatus {
	NEW,        // новая
	IN_PROGRESS,  // в разработке
	TESTING,    // на тестировании
	DONE,       // завершена
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

TasksInfo operator-(const TasksInfo& lhs, const TasksInfo& rhs) {
	TasksInfo t;
	for (auto i : lhs) {
		if (static_cast<int>(i.first) == 3) { break; }
		if (i.second != 0) {
			if (rhs.count(static_cast<TaskStatus>(i.first)) >= 1) {
				i.second -= rhs.at(static_cast<TaskStatus>(i.first));
				if (i.second != 0) { t[static_cast<TaskStatus>(i.first)] = i.second; }
			}
			else {
				t[static_cast<TaskStatus>(i.first)] = i.second;
			}
		}
	}
	return t;
}



TasksInfo operator+(TasksInfo lhs, TasksInfo rhs) {

	TasksInfo temp;

	for (int i = 0; i < 4; ++i) {

		temp[static_cast<TaskStatus>(i)] = lhs[static_cast<TaskStatus>(i)] + rhs[static_cast<TaskStatus>(i)];

	}

	return temp;

}


class TeamTasks {
public:

	void AddNewTask(const string& person) {
		++team[person][TaskStatus::NEW];


	}
	const TasksInfo  GetPersonTasksInfo(const string& person)  const {
		TasksInfo temp;
		for (auto& i : team.at(person)) {
			if (i.second != 0) { temp[i.first] = i.second; }

		}
		return temp;
	}

//	const TasksInfo& GetPersonTasksInfo(const string& person) const {
//
//		return team.at(person);

//	}

	tuple <TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
		if (team.count(person) == 0) {
			return{ {},{} };
		}

		vector<int> v;
		TasksInfo update_person, untouched;

		for (auto & i : team[person]) {
			v.push_back(i.second);
			//cout << i.second << " ";
		}
		//cout << endl;
		//cout << "lengs vector " << v.size() - 1 << endl;
		int count = 0;
		for (int i = 0; i <= v.size() - 1; ++i) {
			//cout << "number vector " << i << " last element vector v[i] = " << v[i] << endl;
			for (int n = 0; n < v[i]; ++n) {
				if (count < task_count) {

					//cout << "num " << count;
					if (i <= 2) {
						update_person[static_cast<TaskStatus>(i + 1)]++;
				//	cout << " <<<< i =  " << i << " i+1 =" << i + 1 << " count = " << count << "n = " << n << endl;
					} else if(i=3){ untouched[static_cast<TaskStatus>(i)]++;
				//	cout << " <<<<< i =  " << i << " i =" << i + 1 << " count = " << count << "n = " << n << endl;
					}
				}

				else
				{
					if (i <= 3) {
						untouched[static_cast<TaskStatus>(i)]++;
					//	cout << " >>>> i =  " << i << " count = " << count << "n = " << n << endl;
					}
				}
				++count;
			}

		}

		team[person] = update_person + untouched;
		TasksInfo t = team[person] - update_person;


		return tie(update_person, t);
	}




private:
	map<string, TasksInfo> team;
};

template <typename Collection>
string Join(const Collection& c, const string& d) {
	stringstream ss;
	bool isFirst = true;
	for (const auto& i : c) {
		if (!isFirst) {
			ss << d;
		}
		isFirst = false;
		ss << i;
	}
	return ss.str();
}
template <typename F, typename S>
ostream& operator <<(ostream& out, const pair<F, S>& p) {
	return out << p.first << ": " << p.second;
}
template <typename K, typename V>
ostream& operator <<(ostream& out, const map<K, V>& m) {
	return out << '{' << Join(m, ", ") << '}';
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
	return out << '[' << Join(v, ", ") << ']';
}
int main() {
	TeamTasks tasks;

	while (cin) {
		string command, person;
		int num;
		cin >> command >> person;
		if (command == "AddNewTasks") {
			cin >> num;
			while (num--)
				tasks.AddNewTask(person);
			cout << "[]" << endl;
		}
		else if (command == "PerformPersonTasks") {
			cin >> num;

			TasksInfo updated_tasks, untouched_tasks;

			// string person ="Alice";
			//int num = 5;
			// for(int i=0; i<5; ++i)
			// tasks.AddNewTask(person);

			tie(updated_tasks, untouched_tasks) =
				tasks.PerformPersonTasks(person, num);

			cout << vector<TasksInfo>{updated_tasks, untouched_tasks } << endl;

		}
		else if (command == "GetPersonTasksInfo") {
			cout << tasks.GetPersonTasksInfo(person) << endl;
		}
		else if (command.size() && command[0] != '#') {
			throw invalid_argument("wrong command: " + command);
		}
	}

}

