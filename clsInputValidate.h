#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
#include"clsUlit.h"
#include"clsString.h"

using namespace std;
class clsInputValidate
{
public:

	 template <typename T> static T IsNumberBetween(T Num1, T Num2, T Num3) {
		 if (Num1 >= Num2) {
			 clsUlit::_Swap(Num1, Num2);
		 }
		 if ((Num1 <= Num3) && (Num2 >= Num3)) {
			 return true;
		 }
		 return false;
	}

	static bool IsDateBetween(clsDate DateNow,clsDate Date1,clsDate Date2) {

		if (clsDate::IsDateOneBeforDateTwo(Date1,Date2)) {
			if (IsNumberBetween<short>(Date1.day, Date2.day, DateNow.day))
				return true;
			else
				return false;
		}
		else {
			clsDate::_swapDate(Date1, Date2);
			IsDateBetween(DateNow, Date1, Date2);
		}
		return false;
	}

	template <typename T> static T ReadNumber(string MessageError = "Invalide Number , please enter agian ") {
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << MessageError << " ";
		}
		return Number;
	}

	template <typename T> static T ReadNumberBetween(T From, T To, string messageErorr = "Number is not withe range, enter again Number  ") {
		T Num = ReadNumber<T>();
		while (!IsNumberBetween<T>(From, To, Num))
		{
			cout << messageErorr;
			Num = ReadNumber<T>();
		}

		return Num;
	}

	static string ReadString() {
		string St;

		getline(cin >> ws, St);

		return St;
	}

	static bool IsValidDate(clsDate Date) {
		return clsDate::ValideDate(Date);
	}

};

