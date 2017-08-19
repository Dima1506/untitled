
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;
class Date {
public:
    Date(string st){
        bool ka=false,ka2=false;
        stringstream t;
        int year,month,day;
        if(st[0]=='-' || st[st.length()-1]=='-'){
            throw runtime_error("Wrong date format: "+st);
        }
        for(int i=0;i<st.size();i++) {
            if (!ka && st[i] != '-') {
                if (!(st[i] >= '0' && st[i] <= 9)) {
                    throw runtime_error("Wrong date format: " + st);
                }
            } else {
                if (!ka) {
                    ka = !ka;
                }
            }
            if (!ka2 && ka && st[i] != '-') {
                if (!(st[i] >= '0' && st[i] <= 9)) {
                    throw runtime_error("Wrong date format: " + st);
                }
            } else {
                if (!ka2) {
                    ka2 = !ka2;
                }
            }
            if (ka2 && ka && st[i] != '-') {
                if (!(st[i] >= '0' && st[i] <= 9)) {
                    throw runtime_error("Wrong date format: " + st);
                }
            }
        }
        t<<st;
        t>>year;
        if(!(year>=0 && year<10000)){
            throw runtime_error("Wrong date format: " + st);
        }
        this->year=year;
        t.ignore(1);
        t>>month;
        if(!(month>=1 && month<=12)){
            throw runtime_error("Month value is invalid: "+to_string(month));
        }
        this->month=month;
        t.ignore(1);
        t>>day;
        if(!(day>=1 && day<=31)){
            throw runtime_error("Day value is invalid: "+to_string(day));
        }
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
    void AddEvent(const Date& date, const string& event){

    }
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    /* ??? */ Find(const Date& date) const;

    void Print() const;

private:
    map <Date,set<string>> dt;
};

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        try {
            stringstream st;
            st << command;
            Date dt("1--1");
        }catch (runtime_error& rn){
            cout<<rn.what();
        }
    }

    return 0;
}