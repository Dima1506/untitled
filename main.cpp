// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <string>
#include <map>
#include <iostream>
using namespace std;
class Date {
public:
    Date(int year,int month,int day){
        this->year=year;
        this->month=month;
        this->day=day;
    }
    int GetYear() const{
        return year;
    }
    int GetMonth() const{
        return month;
    }
    int GetDay() const{
        return day;
    }
private:
    int year,month,day;
};

bool operator<(const Date& lhs, const Date& rhs){
    if(lhs.GetYear()!=rhs.GetYear()){
        return lhs.GetYear()<rhs.GetYear();
    } else {
        if (lhs.GetMonth() != rhs.GetMonth()) {
            return lhs.GetMonth() < rhs.GetMonth();
        } else{
            if(lhs.GetDay()!=rhs.GetDay()){
                return lhs.GetDay()<rhs.GetDay();
            } else{
                return false;
            }
        }
    }
}
class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    /* ??? */ Find(const Date& date) const;

    void Print() const;
};

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        // Считайте команды с потока ввода и обработайте каждую
    }

    return 0;
}