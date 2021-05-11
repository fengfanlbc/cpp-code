#include<iostream>
#include<string>
using namespace std;

struct Student
{
    string name;
    int score;

    bool operator>(const Student& otherStudent){
        return score > otherStudent.score;
    }

    friend ostream& operator<<(ostream &os, Student& otherStudent){
        os << "student:" << otherStudent.name << ", score:" << otherStudent.score << endl;
        return os;
    }
};
