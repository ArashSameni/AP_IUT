#include <iostream>
using namespace std;

class Person
{
    string name;
    char gender;
    string email;

public:
    Person(string _name = "", char _gender = 'm', string _email = "");
    string getName();
    char getGender();
    string getEmail();
    void setName(string _name);
    void setGender(char _gender);
    void setEmail(string _email);
    string getInfo();
};

class Book
{
    string name;
    Person writer;
    int printYear;
    int availablesCount;
    int borrowsCount;
    void setAvailables(int _count);
    void setBorrows(int _count);
    void addOne();
    void removeOne();
    void borrow();
    void getBack();
    friend class Library;

public:
    Book(string _name = "");
    Book(string _name, Person _writer, int _printYear, int _count);
    string getName();
    string getWriterName();
    Person getWriter();
    int getPrintYear();
    int getAvailablesCount();
    int getBorrowsCount();
    void setName(string _name);
    void setWriter(Person _writer);
    void setPrintYear(int _printYear);
};

class Library
{
    string name = "";
    string address = "";
    int startTime = 0;
    int endTime = 0;
    int foundationYear = 0;
    int employeeCount = 0;
    Book *books = nullptr;
    int booksCount = 0;
    int booksTotal = 0;
    int getBookByName(string bookName);
    bool sorted = false;

public:
    Library(string _name);
    Library(string _name, string _address);
    Library(string _name, string _address, int _startTime, int _endTime, int _foundationYear, int empCount);
    string getName();
    string getAddress();
    int getStartTime();
    int getEndTime();
    int getFoundationYear();
    int getEmployeeCount();
    int getBooksCount();
    void setName(string _name);
    void setAddress(string _address);
    void setStartTime(int _startTime);
    void setEndTime(int _endTime);
    void setFoundationYear(int _foundationYear);
    void setEmployeeCount(int count);
    void addBook(Book book);
    bool isAvailable(string bookName);
    void borrow(string bookName);
    void giveBack(string bookName);
    void printBooks();
    void printWriterBooks(string writerName);
    bool isOpen(int time);
};