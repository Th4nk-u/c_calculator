#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <vector>
using namespace std;

class Printer
{
public:
    // Constructor
    Printer(string name, int paper)
    {
        _name = name;
        _availablePaper = paper;
    }

    void Print(string txtdoc)
    {
        int requiredPaper = txtdoc.length() / 10; // Calculate required paper

        if (requiredPaper > _availablePaper)
        {
            throw runtime_error("Not enough paper!");
        }

        cout << "Printing... " << txtdoc << endl;
        _availablePaper -= requiredPaper;
    }

private:
    string _name;
    int _availablePaper;
};

int main()
{
    // Create a vector of Printer objects
    vector<Printer> printers = { Printer("HP Printer", 10),
                                 Printer("Canon Printer", 5),
                                 Printer("Epson Printer", 12) };

    // Select a printer from the vector
    int printerIndex;
    cout << "Select a printer: 0 - HP Printer, 1 - Canon Printer, 2 - Epson Printer" << endl;
    cin >> printerIndex;

    if (printerIndex < 0 || printerIndex >= printers.size())
    {
        cout << "Invalid printer selection." << endl;
        return 1;
    }

    // Use the selected printer
    Printer& selectedPrinter = printers[printerIndex];

    try
    {
        // Print documents using the selected printer
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");
        selectedPrinter.Print("01234567890");


        // Throw an exception to test error handling
        //throw runtime_error("Something went wrong!");
    }
    catch (const runtime_error& e)
    {
        // Catch and handle runtime errors
        cout << "Runtime error: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        // Catch and handle all other exceptions
        cout << "Exception: " << e.what() << endl;
    }
    catch (...)
    {
        // Catch and handle any other errors
        cout << "An error occurred!" << endl;
    }

    // Handle file I/O errors
    try
    {
        ifstream inputFile("nonexistentfile.txt");
        if (!inputFile)
        {
            throw runtime_error("File not found!");
        }
    }
    catch (const runtime_error& e)
    {
        // Catch and handle file I/O errors
        cout << "File I/O error: " << e.what() << endl;
    }

    return 0;
}
