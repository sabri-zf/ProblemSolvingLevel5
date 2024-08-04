#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
#include<queue>
#include<stack>

using namespace std;

class clsQueueLine
{
private:

	int _totalTicket = 0;
	string _preFix="";
	int _timeWating=0;


	class clsTickte {

		int _number;
		int _avrigeTime;
		string _prefix;
		int _clientWating;

		void _GetDate() {
			clsDate date;
			cout << date.TimeToString(clsDate()) << " / " << date.DateToString(clsDate());
		}

	public:

		 clsTickte(string prefix, int totalticket, int clientwating, int avregTime) {
			_prefix = prefix;
			_number = totalticket;
			_clientWating = clientwating;
			_avrigeTime = avregTime;
		}

		 string  fullNumber() {
			 return _prefix + to_string(_number);
		 }

		 int AvregeTime() {
			 return _avrigeTime * _clientWating;
		 }

		 void printTicket() {
			 cout << "\n\t\t----------------------\n";

			 cout << "\t\t" << fullNumber()<< endl;
			 cout << "\t\t";
			 _GetDate();
			 cout << "\n\t\t Wating Client : " << _clientWating << endl;
			 cout << "\t\t" << "Time serving is \n";
			 cout << "\t\t" << AvregeTime()<< " Miuntes";

			 cout << "\n\t\t------------------------\n";

		 }

	};

public:

	queue<clsTickte> QueueLine;

	clsQueueLine(string prfix, int timewating) {
		_preFix = prfix;
		_timeWating = timewating;
		_totalTicket = 0;
	}

	void issueTicket() {
		_totalTicket++;
		
		clsTickte ticket(_preFix, _totalTicket, clientWating(), _timeWating);

		QueueLine.push(ticket);
	}

	int clientWating() {
		return QueueLine.size();
	}

	string WhoIsNext() {
		if (QueueLine.empty()) {
			return "not found next!\n";

		}
		return QueueLine.front().fullNumber();

	}

	bool sirvedNextClinet() {
		if (QueueLine.empty()) {
			cout << "Not Have client serves !\n";
			return false;
		}

		QueueLine.pop();
		return true;
	}
	int sirvedClient() {
		return _totalTicket - clientWating();
	}

	void printInfo() {

		cout << "\n\n--------------------------\n";
		cout << "prefix = " << _preFix << endl;
		cout << "Total Ticket = " << _totalTicket << endl;
		cout << "served Client = " << sirvedClient()  << endl;
		cout << "wating Client = " << clientWating();
		cout << "\n--------------------------\n";
	}


	bool PrintTicketsLineRTL() {

		if (_totalTicket == 0) {
			cout << "\n we need isuuse ticket befor print !! \n";
			return false;
		}

		queue<clsTickte> tempTicket= QueueLine;
		while(!tempTicket.empty()) {
			cout << tempTicket.front().fullNumber() << " <- ";
			tempTicket.pop();
		}

		cout << endl;
		return true;
	}

	bool PrintTicketsLineLTR() {

		if (_totalTicket == 0) {
			cout << "\n we need isuuse ticket befor print !! \n";
			return false;
		}

		queue<clsTickte> tempTicket = QueueLine;
		stack<clsTickte> tempStac;

		while (!tempTicket.empty()) {
			tempStac.push(tempTicket.front());
			tempTicket.pop();
		}

		while (!tempStac.empty()) {
		cout<<	tempStac.top().fullNumber()<<" -> ";
		   tempStac.pop();
		}

		cout << endl;

		return true;
	}


	void printAllTickets() {

		if (!QueueLine.empty()) {
			cout << "++ ALL TICKET ++\n";
		}
		else {
			cout << "++ sorry the ticket is not ++\n";
		}

		queue<clsTickte> tempTicket = QueueLine;

		while (!tempTicket.empty())
		{
			tempTicket.front().printTicket();

			tempTicket.pop();
		}
	}

	

};

