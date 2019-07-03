#include "contact.h"
#include <vector>
#include <iostream>
using namespace std;

class PhoneBook
{
public:

    PhoneBook();
    void addContact(Contact contact);
    void removeContact(Contact contact);
    vector<Contact> findContact(string str);
    vector<Contact> getAllContacts();
private:
    vector<Contact> contactsAr;
};


