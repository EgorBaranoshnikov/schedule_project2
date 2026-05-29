void number_lessons_subject(vector<School_Class> school_class, int class_quantity) {
    vector<vector<pair<int, int>>> school_class2(class_quantity);
    for (int i = 0; i < class_quantity; i++) {
        school_class2[i].resize(school_class[i].quantity_lessons);
        for (int j = 0; j < school_class[i].quantity_lessons; j++) {
            school_class2[i][j].first = school_class[i].lessons_name_quantity[j].second / 5;
            school_class2[i][j].second = school_class[i].lessons_name_quantity[j].second % 5;
        }
    }
}


for (int i = 0; i < class_quantity; i++) {
        number_lessons_subject(school_class[i]);
    }