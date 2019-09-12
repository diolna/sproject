#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <exception>
#include <set>
//#include <algorithm>   // Не нужно
#include <iomanip>

// повторный ввод. я не прозвожу поиск. просто добавляю в базу. при добавлении ни чего не происходит если это уже есть

using namespace std;

class Date {
public:
	Date(){
		year = 0;
		month =0;
		day = 0;
	}

	Date(const string& d){
			stringstream input(d);
			char d2,d1;
			input >> year>>d1>>month>>d2>>day;
			if(d1=='-'&& d2 =='-'){
				if(!input.eof() ){
					throw invalid_argument("Wrong date format: " + d);
				}
				if(year >9999){
					throw invalid_argument("Wrong date format: " + d);
				}
				if(month <=0 || month>12){
					throw invalid_argument("Month value is invalid: " + to_string(month));
				}else if(day <=0 || day>31){
					throw invalid_argument( "Day value is invalid: " + to_string(day));
				}
			}else{
				throw invalid_argument("Wrong date format: " + d);
			}


/*
			input >> year;
			if(input.peek()!='-'){
					throw invalid_argument("Wrong date format: " + d);
			}
			input.ignore(1);
			if((input.peek()>'9'|| input.peek()<'0')&& input.peek()!='-'){
				throw invalid_argument("Wrong date format: " + d);
			}
			input >> month;


			if(month>12 || month <=0){
				throw invalid_argument("Month value is invalid: " + to_string(month));
			}
			if(input.peek()!='-'){
				throw invalid_argument("Wrong date format: " + d);
			}
			input.ignore(1);
			if((input.peek()>'9'|| input.peek()<'0')&& input.peek()!='-'){
							throw invalid_argument("Wrong date format: " + d);
						}
			input >> day;

				if(day>31 || day <=0){
					throw invalid_argument( "Day value is invalid: " + to_string(day));

				}


			if(!input.eof()){
				throw invalid_argument("Wrong date format: " + d);
			}
*/

	}
  int GetYear() const{
	  return year;
  }
  int GetMonth() const{
	  return month;
  }
  int GetDay() const{
	  return day;

  }
private:
  int year;
  int month;
  int day;


};

bool operator<(const Date& lhs, const Date& rhs){
	bool y=lhs.GetYear()<rhs.GetYear();
	bool m =lhs.GetMonth()< rhs.GetMonth();
	bool d = lhs.GetDay()< rhs.GetDay();
	bool equal_y =lhs.GetYear()==rhs.GetYear();
	bool equal_m = lhs.GetMonth()== rhs.GetMonth();
	return (y || (equal_y&& m) || (equal_y&& equal_m && d));

}
bool operator==(const Date& lhs, const Date& rhs){
	return (lhs.GetYear()== rhs.GetYear() && lhs.GetMonth()== rhs.GetMonth() &&
		   lhs.GetDay()== rhs.GetDay());
}
ostream& operator <<(ostream & stream, const Date& date){
				stream << setfill('0');
				stream << setw(4)<< date.GetYear() << '-' << setw(2) << date.GetMonth()
								 << '-'<< setw(2) << date.GetDay();
				return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event){
	  // нужно проверить существует ли данный ключ в словаре. если такая дата есть то просто добалвяем событие
	  // а обьект дата должен біть удален что бы не плодить обьекты лишние
	   base[date].insert(event);
 }
  bool DeleteEvent(const Date& date, const string& event){
	   	  for(auto& i: base){

			  if(i.first == date){

				   for(auto& n: i.second){
					  if(n== event){
						  (i.second).erase(event);  // Ключ остается. В идеале проверить контейнер set если от пуст, то удалить ключ
						  return true;
					  }

				  }
			  }

	  }
	  return false;
  }

  int  DeleteDate(const Date& date){
	  for(auto& i: base){
	  	  if(i.first == date){
	  		int n = i.second.size();
	  		while(!i.second.empty()){
	  			auto iterator = i.second.end();
	  			-- iterator;
	  		i.second.erase(iterator);
	  	 		}
	  		 return n;
	  	   }
	  }
	// return 1;
  }

  set<string> Find(const Date& date) const {

	  	  	  	  set<string> events={""};
	  	  	  	  if(base.count(date)>0){
	  	  	  	  events = base.at(date);
	  	  	  	  return events;
	  	  	  	  }else{
	  	  	  		  return events;
	  	  	  	  }
  }

/*
  void Find(const Date& date) const{
	  set<string> temp;

	  	  for(auto& i: base){
	  		  if(i.first == date){
	  			  temp = i.second;
	  			  for(auto n: temp){
	  				  cout << n << endl;
	  			  }
	  		  }
	  	  }
  }
*/
  void Print() const{
	  	  for(auto & i: base){
	  		  	  for(auto& n: i.second){
	  			  cout << i.first << " " << n << endl;
	  		  }
	  	  }
  }

private:

 //set<string> events;
  map<Date, set<string>> base;           //?? сортировка set что то не работает
};


Date GetDate(stringstream& stream){

	string date ;
	 stream >> date;
	 return {date};
}

int main() {
  Database db;

  string command;

  while (getline(cin, command)) {
	  stringstream input(command);
	  string op;
	  input >> op;


    // Считайте команды с потока ввода и обработайте каждую
	//Date new_date;
	  try {
	 	 if(op == "Add"){
	 		Date new_date;
		  new_date = GetDate(input);

		  string event;
		 input >> event;
		 db.AddEvent(new_date,event);


	 }else if(op == "Del"){
		 Date new_date;
		 new_date = GetDate(input);
		 if(input.eof()){
			// cout << "eof";
			 cout << "Deleted "<< db.DeleteDate(new_date)<< " events"<< endl;

		 }else{

			  string event;
			  input >> event;

			 bool res =db.DeleteEvent(new_date, event);
			 if(res== true){
				 cout << "Deleted successfully" << endl;
			 }else{
				 cout << "Event not found" << endl;
			 }
		 }
	 }else if(op == "Print"){
		 	 db.Print();
	 }else if(op =="Find"){
		  Date new_date;
		 new_date = GetDate(input);
		// db.Find(new_date);
		 set<string> events = db.Find(new_date);
		 for(auto i: events){
			 cout << i << endl;
		 }
	 }else if(op ==""){
	 }else{
	 	 throw runtime_error("Unknown command: " + op);
	 }
	 } catch (invalid_argument& ia){
  		 	 cout << ia.what();
  		 	 return 0;
  	 }catch (exception& ex){
  		 cout << ex.what();
  		 return 0;
  	 }




  }
  return 0;
}
