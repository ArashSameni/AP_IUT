#include <iostream>
#include "Library.h"
using namespace std;

int main()
{
    Person arash("Arash", 'm', "Arash@Email.Com");
    Person mamad("Mamad", 'm', "Mamad@Email.Com");
    Person zahra("zahra", 'f', "Zahra@Email.Com");

    Book aBook("How to kill teacher assistants", arash, 2021, 100);
    Book a2Book("Test2", arash, 2020, 100);
    Book mBook("Zamad", mamad, 2019, 50);
    Book zBook("Test", zahra, 2018, 1);
    
    Library isfLab("Isfahan Library", "Isfahaaaaan", 7, 15, 2000, 50);
    isfLab.addBook(aBook);
    isfLab.printBooks();
    cout << isfLab.getBooksCount() << endl;

    isfLab.addBook(mBook);
    isfLab.addBook(a2Book);
    isfLab.addBook(zBook);
    cout << isfLab.getBooksCount() << endl;
    cout << isfLab.isOpen(12) << endl;

    cout << isfLab.isAvailable("Test") << endl;
    isfLab.borrow("tttt");
    isfLab.borrow("Test");
    cout << isfLab.isAvailable("Test") << endl;
    isfLab.giveBack("Test");
    cout << isfLab.isAvailable("Test") << endl;
    isfLab.printBooks();
    cout << endl;
    isfLab.printWriterBooks("Arash");
}