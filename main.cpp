#include <iostream>
#include <vector>
// #include <set>
// #include <ctime>
#include <string>
#include <fstream>
#include <cmath>
// #include <map>
using namespace std;

class School_Class {
public:
    string name_class;
    int quantity_lessons;
    vector<pair<string, int>> lessons_name_quantity; // 1 - название предмета, 2 - кол. раз в неделе

    void set_School_Class(ifstream &file1) {
        file1 >> name_class;
        file1 >> quantity_lessons;
        lessons_name_quantity.resize(quantity_lessons);
        for (int i = 0; i < quantity_lessons; i++) {
            file1 >> lessons_name_quantity[i].first;
            file1 >> lessons_name_quantity[i].second;
        }
    }
};

class School_Teacher {
public:
    string name_teacher;
    int quantity_classs_teaches;
    vector<int> classs_teaches;
    string name_subject;
    int difficulty_subject;

    void set_School_Teacher(ifstream &file2) {
        file2 >> name_teacher;
        file2 >> quantity_classs_teaches;
        if (quantity_classs_teaches != 0) {
            classs_teaches.resize(quantity_classs_teaches);
            for (int i = 0; i < quantity_classs_teaches; i++) {
                file2 >> classs_teaches[i];
            }
            file2 >> name_subject;
            file2 >> difficulty_subject;
        }
    }
};

int main() {
    int class_quantity, teacher_quantity;

    ifstream file1("1file_pr.txt");
    ifstream file2("2file_pr.txt");
    file1 >> class_quantity;
    file2 >> teacher_quantity;
    vector<School_Class> school_class(class_quantity);
    vector<School_Teacher> school_teacher(teacher_quantity);
    for (int i = 0; i < class_quantity; i++) {
        school_class[i].set_School_Class(file1);
    } for (int i = 0; i < teacher_quantity; i++) {
        school_teacher[i].set_School_Teacher(file2);
    }
}