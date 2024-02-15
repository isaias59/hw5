#include "string.hpp"
#include <cstring>
#include <utility>

//Precondition:take c-string
//Post:Creates object
String::String(const char* s) : head(list::from_string(s)) {}

//Pre:Takes String object
//Post: Makes new String object
String::String(const String& s) : head(list::copy(s.head)) {}

//Pre: Takes String object
//Post: Moves to new String objecy
String::String(String&& s) noexcept : head(nullptr) {
    s.swap(*this);
}

//Pre: None
//Post: Deletes String object
String::~String() {
    list::free(head);
}

//Pre: Gets String object
//Post: Swaps linked list
void String::swap(String& s) {
    std::swap(head, s.head);
}


//Pre:Gets String Object
//Post: Steals data
String& String::operator=(const String& s) {
    String temp(s);
    temp.swap(*this);
    return *this;
}

//Pre: Takes String object
//Post: 
String& String::operator=(String&& s) noexcept {
    if (this != &s) {
        list::free(head);
        head = s.head;
        s.head = nullptr;
    }
    return *this;
}

//Pre: takes strnig object
//Post: returns true if both strings match
bool String::operator==(const String& s) const {
    return list::compare(head, s.head) == 0;
}

// Less-than operator
//bool String::operator<(const String& s) const {
  //  return list::compare(head, s.head) < 0;
//}

//Pre: none
//Post: Returns comncated string
String String::operator+(const String& s) const {
    list::Node* newHead = list::append(head, s.head);
    return String(newHead);
}

//Pre: Gets string object
//Post: Concates string object
String& String::operator+=(const String& s) {
    list::Node* newHead = list::append(head, s.head);
    list::free(head);
    head = newHead;
    return *this;
}

//Pre: takes int input
//Post: Returns the index #
char String::operator[](int index) const {
    list::Node* node = list::nth(head, index);
    return node ? node->data : '\0';
}
//Pre:none
//Post: returns # of charters in the string object
int String::size() const {
    return list::length(head);
}
//Pre:none
//Post: Returns new reversed string object
String String::reverse() const {
    list::Node* reversedHead = list::reverse(head);
    return String(reversedHead);
}
//Pre: Gets character as input
//Post: Returns index of charater
int String::indexOf(char c) const {
    list::Node* node = list::find_char(head, c);
    return node ? list::index(head, node) : -1;
}
//Pre: Takes String object
//Post: Returns the index
int String::indexOf(const String& s) const {
    list::Node* node = list::find_list(head, s.head);
    return node ? list::index(head, node) : -1;
}

//Pre: gets the output
//Post: prints from string object
void String::print(std::ostream& out) const {
    list::print(out, head);
}

//Pre:Takes user input
//Post: Reads and assigns to string object
void String::read(std::istream& in) {
    char buffer[256];
    in.getline(buffer, 256); // Use getline to read the entire line
    *this = String(buffer);
}

//pre: none
//post: prints out
std::ostream& operator<<(std::ostream& out, const String& s) {
    s.print(out);
    return out;
}

//Pre: none
//Post: reads
std::istream& operator>>(std::istream& in, String& s) {
    s.read(in);
    return in;
}

//Pre: Takes string object
//Post: Measures value between two string objects
std::strong_ordering String::operator<=>(const String &s) const {
    int result = list::compare(this->head, s.head);
    if (result < 0) return std::strong_ordering::less;
    if (result > 0) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

//Pre: Has pointer
//Post:Constructs string object
String::String(list::Node* nodeHead) : head(nodeHead) {
}


