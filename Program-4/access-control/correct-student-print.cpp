void Student::print() const /* correct-student-print.cpp */
{
    cout << "--- Student details ---" << endl
         << "Name: " << get_name() << endl
         << "Dept: " << get_dept() << endl
         << "Enrolled in:" << endl;

    for (int i = 0; i < num_courses; i++) 
        enrolled[i].print();
}
