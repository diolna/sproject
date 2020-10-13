#include <iostream>
#include <string>

using namespace std;


class INotifier {

public:
	INotifier(const string& contact): contact_(contact){}
	virtual void Notify(const string& messge)= 0;

	const string contact_;
};

class SmsNotifier : public INotifier{
public:
	SmsNotifier(const string& tel): INotifier(tel){};

	void Notify(const string& message) override {

		SendSms(contact_, message);
	}
private:
	void SendSms(const string& number, const string& message) {
	  cout << "Send '" << message << "' to number " << number << endl;
	}

};

class EmailNotifier : public INotifier {
public:
	EmailNotifier(const string& em) : INotifier(em){}
	void Notify(const string& message) override {

		SendEmail(contact_, message);
		}
private:
	void SendEmail(const string& email, const string& message) {
	  cout << "Send '" << message << "' to e-mail "  << email << endl;
	}

};




void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}