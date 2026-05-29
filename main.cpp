#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class School_Class {
public:
    string name_class;
    int quantity_lessons;
    vector<pair<string, int>> lessons_name_quantity; // 1 - название предмета, 2 - кол. раз в неделе

public:
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
    int quantity_class_teaches; // подходящие классы (цифры)
    vector<int> classs_teaches;
    string name_subject;
    int difficulty_subject;

public:
    void set_School_Teacher(ifstream &file2) {
        file2 >> name_teacher;
        file2 >> quantity_class_teaches;
        if (quantity_class_teaches != 0) {
            classs_teaches.resize(quantity_class_teaches);
            for (int i = 0; i < quantity_class_teaches; i++) {
                file2 >> classs_teaches[i];
            }
            file2 >> name_subject;
            file2 >> difficulty_subject;
        }
    }
};

class School_Class_Dop {
public:
    string name_class;
    string name_teacher_class;
    int days_week;
    int amount_repeat_subject;
    vector<pair<string, int>> repeat_subject;

    vector<pair<int, int>> lessons_average;
    int lessons_day;

public:
    void set_School_Class_Dop() {
        ifstream file3("3file_pr.txt");
        file3 >> name_class;
        file3 >> name_teacher_class;
        file3 >> days_week;
        file3 >> amount_repeat_subject;
        repeat_subject.resize(amount_repeat_subject);
        for (int i = 0; i < amount_repeat_subject; i++) {
            file3 >> repeat_subject[i].first;
            file3 >> repeat_subject[i].second;
        }
    }
};

class Schedule_lesson {
public:
    string lessons;
    string teacher;
};
class Schedule_class {
public:
    vector<Schedule_lesson> schedule_lesson;
    string class_teacher;
    int school_days;
};

void number_lessons_subject(School_Class &school_class, School_Class_Dop &school_class_dop) {
    school_class_dop.lessons_average.resize(school_class.quantity_lessons);
    for (int i = 0; i < school_class.quantity_lessons; i++) {
        school_class_dop.lessons_average[i].first = school_class.lessons_name_quantity[i].second / 5;
        school_class_dop.lessons_average[i].second = school_class.lessons_name_quantity[i].second % 5;
    }
}

void number_lessons_day(School_Class &school_class, School_Class_Dop &school_class_dop) {
    int lessons = 0;
    for (int i = 0; i < school_class.quantity_lessons; i++) {
        lessons += school_class.lessons_name_quantity[i].second;
    }
    school_class_dop.lessons_day = int(lessons / school_class.quantity_lessons) + 1;
}

int difficulty_score_day () {

}

int main() {
    int class_quantity, teacher_quantity;

    ifstream file1("1file_pr.txt");
    ifstream file2("2file_pr.txt");
    file1 >> class_quantity;
    file2 >> teacher_quantity;

    vector<School_Class> school_class(class_quantity);
    vector<School_Teacher> school_teacher(teacher_quantity);
    vector<School_Class_Dop> school_class_dop(class_quantity);

    for (int i = 0; i < class_quantity; i++) {
        school_class[i].set_School_Class(file1);
    } for (int i = 0; i < teacher_quantity; i++) {
        school_teacher[i].set_School_Teacher(file2);
    } for (int i = 0; i < class_quantity; i++) {
        school_class_dop[i].set_School_Class_Dop();
    } for (int i = 0; i < class_quantity; i++) {
        number_lessons_subject(school_class[i], school_class_dop[i]);
        number_lessons_day(school_class[i], school_class_dop[i]);
    }
}