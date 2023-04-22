
#include <iostream>
#include<string>
using namespace std;

class Printer
{
public:
	//contructor
	Printer(string name, int paper)
	{
		_name = name;
		_availablePaper = paper;
	}
	void Print(string txtdoc) 
	{
		int requiredPaper = txtdoc.length() / 10;//40/10=4

		if (requiredPaper>_availablePaper)
		{
			// select only 1 throw
			throw "no paper";
			throw 404;
			/*
			return;
			*/
		}

		cout << "printing..." << txtdoc << endl;
		_availablePaper -= requiredPaper;
	}

private:
	string _name;
	int _availablePaper;
};


int main()
{
	//object named "hp printer" with int value for paper
	Printer myPrinter("hp printer", 10);
	try
	{
		myPrinter.Print("hello, world. try, throw, catch, exeption 123456789");
		myPrinter.Print("hello, world. try, throw, catch, exeption 123456789");
		myPrinter.Print("hello, world. try, throw, catch, exeption 123456789");
	}
	catch (const char * txtException)
	{
		cout << "exception: " << txtException << endl;
	}
	catch (int codeException)
	{
		cout << "exception: " << codeException << " Page not found" << endl;
	}
	/*
	Default catch handler
	catch (...) 
	{
		cout << "Exception happened!" << endl;
	}
	*/


	system("pause>nul");
	return 0;
}
