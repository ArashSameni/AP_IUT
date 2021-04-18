#include "Library.h"

//Person
Person::Person(string _name, char _gender, string _email)
{
    name = _name;
    if (_gender == 'm' || _gender == 'f')
        gender = _gender;
    else
        gender = 'm';
    email = _email;
}
string Person::getName() { return name; }
char Person::getGender() { return gender; }
string Person::getEmail() { return email; }
void Person::setName(string _name) { name = _name; }
void Person::setGender(char _gender)
{
    if (_gender == 'm' || _gender == 'f')
        gender = _gender;
    else
        gender = 'm';
}
void Person::setEmail(string _email) { email = _email; }
string Person::getInfo()
{
    return name + "(" + gender + ") at " + email;
}

//Book
Book::Book(string _name) { name = _name; }
Book::Book(string _name, Person _writer, int _printYear, int _count)
{
    name = _name;
    writer = _writer;
    printYear = _printYear;
    availablesCount = _count;
    borrowsCount = 0;
}
string Book::getName() { return name; }
string Book::getWriterName() { return writer.getName(); }
Person Book::getWriter() { return writer; }
int Book::getPrintYear() { return printYear; }
int Book::getAvailablesCount() { return availablesCount; }
int Book::getBorrowsCount() { return borrowsCount; }
void Book::setName(string _name) { name = _name; }
void Book::setWriter(Person _writer) { writer = _writer; }
void Book::setPrintYear(int _printYear) { printYear = _printYear; }
void Book::setAvailables(int _count) { availablesCount = _count; }
void Book::setBorrows(int _count) { borrowsCount = _count; }
void Book::addOne() { availablesCount++; }
void Book::removeOne()
{
    if (availablesCount > 0)
        availablesCount--;
}
void Book::borrow()
{
    if (availablesCount > 0)
    {
        availablesCount--;
        borrowsCount++;
    }
}
void Book::getBack()
{
    if (borrowsCount > 0)
    {
        borrowsCount--;
        availablesCount++;
    }
}

//Library
Library::Library(string _name = "") { name = _name; }
Library::Library(string _name = "", string _address = "")
{
    name = _name;
    address = _address;
}
Library::Library(string _name, string _address, int _startTime, int _endTime, int _foundationYear, int empCount)
{
    name = _name;
    address = _address;
    startTime = _startTime;
    endTime = _endTime;
    foundationYear = _foundationYear;
    employeeCount = empCount;
}
string Library::getName() { return name; }
string Library::getAddress() { return address; }
int Library::getStartTime() { return startTime; }
int Library::getEndTime() { return endTime; }
int Library::getFoundationYear() { return foundationYear; }
int Library::getEmployeeCount() { return employeeCount; }
int Library::getBooksCount() { return booksTotal; }
void Library::setName(string _name) { name = _name; }
void Library::setAddress(string _address) { address = _address; }
void Library::setStartTime(int _startTime) { startTime = _startTime; }
void Library::setEndTime(int _endTime) { endTime = _endTime; }
void Library::setFoundationYear(int _foundationYear) { foundationYear = _foundationYear; }
void Library::setEmployeeCount(int count) { employeeCount = count; }
int Library::getBookByName(string bookName)
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getName() == bookName)
            return i;
    }
    return -1;
}
void Library::addBook(Book book)
{
    Book *newBooks = new Book[++booksCount];
    sorted = false;
    booksTotal += book.getAvailablesCount();
    booksTotal += book.getBorrowsCount();
    newBooks[booksCount - 1] = book;
    if (booksCount > 1)
    {
        for (int i = 0; i < booksCount - 1; i++)
            newBooks[i] = books[i];
        delete[] books;
    }
    books = newBooks;
}
bool Library::isAvailable(string bookName)
{
    int index = getBookByName(bookName);
    if (index != -1)
        return books[index].getAvailablesCount() > 0;
    else
        return false;
}
void Library::borrow(string bookName)
{
    if (isAvailable(bookName))
    {
        int index = getBookByName(bookName);
        books[index].borrow();
    }
    else
        cout << "Book isn't available!" << endl;
}
void Library::giveBack(string bookName)
{
    int index = getBookByName(bookName);
    if (index != -1)
        books[index].getBack();
    else
        cout << "Book not found!" << endl;
}
void Library::printBooks()
{
    if (!sorted)
    {
        for (int i = 0; i < booksCount - 1; i++)
            for (int j = i + 1; j < booksCount; j++)
                if (books[j].getName() < books[i].getName())
                {
                    Book tmp = books[i];
                    books[i] = books[j];
                    books[j] = tmp;
                }

        sorted = true;
    }

    cout << "Book Name | Print Year | Count | Writer" << endl;
    for (int i = 0; i < booksCount; i++)
    {
        int count = books[i].getAvailablesCount() + books[i].getBorrowsCount();
        cout << books[i].getName() << " | ";
        cout << books[i].getPrintYear() << " | ";
        cout << count << " | ";
        cout << books[i].getWriter().getInfo() << endl;
    }
}
void Library::printWriterBooks(string writerName)
{
    cout << "Book Name | Print Year | Count | Writer" << endl;
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getWriterName() == writerName)
        {
            int count = books[i].getAvailablesCount() + books[i].getBorrowsCount();
            cout << books[i].getName() << " | ";
            cout << books[i].getPrintYear() << " | ";
            cout << count << " | ";
            cout << books[i].getWriter().getInfo() << endl;
        }
    }
}
bool Library::isOpen(int time)
{
    return time >= startTime && time <= endTime;
}