
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
class Date {
public:
    Date(string st){
        int l=0;
        stringstream t;
        int year,month,day;
        if(st[0]=='-' || st[st.length()-1]=='-'){
            throw runtime_error("Wrong date format: "+st);
        }
        for(int i=0;i<st.length();i++){
            if(st[i]!='-'){
                if(!('0'<=st[i] && st[i]<='9')) {
                    throw runtime_error("Wrong date format: "+st);
                }
            }
            else{
                if(st[i+1]=='-'){
                    throw runtime_error("Wrong date format: "+st);
                }
                l++;
            }
        }
        if(l!=2){
            throw runtime_error("Wrong date format: "+st);
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
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else{
        return lhs.GetDay() != rhs.GetDay() ? lhs.GetDay() < rhs.GetDay() : false;
    }
}
class Database {
public:
    void AddEvent(const Date& date, const string& event){
        dt[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event){
        if (dt.at(date).count(event) == 1) {
            dt[date].erase(event);
            return true;
        }
        else return false;

    }
    int  DeleteDate(const Date& date){
        int q = dt.at(date).size();
        dt.erase(date);
        return q;
    }

    void Find(const Date& date) {
        set <string> temp;
        temp = dt[to_string(date.GetYear()) + "-" + to_string(date.GetMonth()) + "-" + to_string(date.GetDay())];
        for(auto& l:temp){
            cout<<l<<" ";
        }
        if(dt.at(date).size()!=0){
            cout<<"\n";
        }
    }

    void Print() const{
        for(auto& p:dt){
            cout.fill('0');
            cout<<setw(4)<<p.first.GetYear()<<"-"<<setw(2)<<p.first.GetMonth()<<"-"<<setw(2)<<p.first.GetDay()<<" ";
            for(auto&  o:p.second){
                cout<<o<<" ";
            }
            cout<<"\n";
        }
    }

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
            string date,io,event;
            string command2;
            st>>command2;
            if(command2=="Add"){
                st>>date>>event>>io;
                if(date==""){
                    throw runtime_error("Wrong date format: " + date);
                }
                if(event=="" || io!=""){
                    throw runtime_error("Unknown command: "+command2);
                }
                db.AddEvent(Date(date),event);
            }else if(command2=="Del") {
                st >> date >> event;
                if(date==""){
                    throw runtime_error("Wrong date format: " + date);
                }
                if (event == "") {
                    cout << "Deleted " << db.DeleteDate(Date(date)) << " events\n";
                } else {
                    st >> io;
                    if (io != "") {
                        throw runtime_error("Unknown command: " + command);
                    }
                    if(db.DeleteEvent(Date(date), event)) {
                        cout << "Deleted successfully\n";
                    }
                }
            }
            else if(command2=="Find"){
                string date,io;
                st>>date>>io;
                if(io!=""){
                    throw runtime_error("Unknown command: "+command);
                }
                db.Find(Date(date));
            }else if(command2=="Print") {
                db.Print();
            }else if(command2==""){

            } else{
                throw runtime_error("Unknown command: "+command2);
            }
        }catch (runtime_error& rn){
            cout<<rn.what();
            break;
        }
    }

    return 0;
}