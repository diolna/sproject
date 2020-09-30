
#include <iostream>
#include "Queue.h"
#include "Customer.h"
#include <ctime>
#include <cstdlib>

const int MIN_PER_HR = 60;


bool newcustomer(double x);

int main() {

	srand(time(0)); // случайная инициализация rand

	std::cout << "Case Study: Bank of Heather Automatic Teller\n";
	std::cout << "Enter maximal size of queue: ";
	int qs;
	std::cin>>qs;


	Queue<Customer> line(qs);

	std::cout << "Enter the number of simulation hours: ";
	int hours;
	std::cin >> hours;

	long cyclelimit = MIN_PER_HR * hours;

	std::cout << "Enter the average number of customer per hour: ";
	double perhour;
	std::cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR;
	Customer temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	int sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for(int cycle = 0; cycle < cyclelimit; cycle++){
		if(newcustomer(min_per_cust)){
			if(line.isfull())
				turnaways++;
			else{
				customers++;
			temp.set(cycle);
			line.enqueue(temp);
			}
		}
		if(wait_time <=0 && !line.isempty()){
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if(wait_time > 0){
			wait_time --;
		}
			sum_line +=  line.queuecount();

	}
if(customers > 0){
	std::cout << "customers accepted: " << customers << "\n";
	std::cout << "  customers served: " << served << "\n";
	std::cout << "         turnaways: " << turnaways << "\n";
	std::cout << "average queue size: ";
	std::cout.precision(2);
	std::cout.setf(std::ios_base::showpoint);
	std::cout << (double) sum_line / cyclelimit << "\n";
	std::cout << "average wait time: "
			<< (double) line_wait/served << " minutes\n";


}
else
{
	std::cout << "No customers!\n";
}

	return 0;
}


bool newcustomer(double x){
	return (rand() * x / RAND_MAX < 1);  //value RAND_MAX determined in cstdlib and indicate the largest number returned
											// function rand()
}
