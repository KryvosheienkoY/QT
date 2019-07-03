#include <iostream>
using namespace std;

class Contact
{
public:
    string _name;
    string _number;
    Contact(string name, string number): _name(name), _number(number){
        return;
    }
    bool operator==(const Contact& c)
    {
        return ((_name == c._name)&(_number==c._number));
    }
};
