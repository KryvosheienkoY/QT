#include "phonebook.h"
#include <vector>
#include <iostream>
using namespace std;

PhoneBook::PhoneBook()
{
    return;
}
void PhoneBook::addContact(Contact contact)
{
    contactsAr.push_back(contact);
    return;
}

void PhoneBook::removeContact(Contact contact)
{
    int count =1;
    for (std::vector<Contact>::iterator it = contactsAr.begin() ; it != contactsAr.end(); ++it)
    {
        if ( it->_name == contact._name || it->_number == contact._number ) {
            break;
        }
        count++;
    }
    contactsAr.erase(contactsAr.begin()+count);
    return;
}

vector<Contact> PhoneBook::findContact(string str){
    vector<Contact> foundAr;
    for (std::vector<Contact>::iterator it = contactsAr.begin() ; it != contactsAr.end(); ++it)
    {
        if (it->_name == str || it->_number == str  ) {
           foundAr.push_back(*it);
        }
    }
    return foundAr;
}
vector<Contact> PhoneBook::getAllContacts(){
    return contactsAr;
}

