/*
 * student.cpp
 *
 */

#include "student.h"
using namespace std;

/* TODO: Constructors
 * - history is a pointer to an int array, storing completed courses
 * - num is the length of this array
 * When cp_type = AVL_CP, store course_plan as an AVL tree; otherwise store course_plan as a BST
 */
Student::Student(const string& id, const int* history, int num, CP_TYPE cp_type): id(id)
{
    for (int i = 0; i < num; i++) {
        this->course_history.insert(history[i]);
    }
    if (static_cast<int>(cp_type) == 0)
        this->course_plan = new BST<Course, int>;
    else
        this->course_plan = new AVL<Course, int>;
}


/* TODO: Add a course into course_history
 *   course_db is a database containing all valid courses, stored in an STL map
 *   The key values used in the STL map are the course code
 */
void Student::update_course_history(const map<int, Course>& course_db, int code)
{
    map<int, Course>::const_iterator it;
    it = course_db.find(code);
    if (it != course_db.end()) {
        this->course_history.insert(code);
    } else {
        cout << id << ": Fail to update history with an invalid course COMP" << code << endl;
    }

}


/* TODO:
 * Print completed courses in ascending order of the course codes
 * Remark: You should use the BT iterator to go through the course history
 *         which is an STL set.
 */
void Student::print_course_history() const
{
    cout << id << ": Course history: ";

    for (set<int>::iterator it = this->course_history.begin(); it != this->course_history.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}


/* TODO: Add a course into course_plan
 *   course_db is a database containing all valid courses, stored in an STL map
 *   The key values used in the STL map are the course code
 */
void Student::enroll(const map<int, Course>& course_db, int code)
{
    map<int, Course>::const_iterator m_it;
    m_it = course_db.find(code);
    if (m_it != course_db.end()) {
        for (int i = 0; i < course_db.find(code)->second.get_num_prerequisites(); i++) {
            if (this->course_history.find(course_db.find(code)->second.get_prerequisites(i)) == this->course_history.end()) {
                cout << id << ": Can't enroll COMP" << code << ". Not all pre-requisites are satisfied yet." << endl;
                return;
            }
        }
        this->course_plan->insert(course_db.find(code)->second, code);
    } else {
        cout << id << ": Fail to enroll an invalid course COMP" << code << endl;
    }


}

/* TODO:
 * Remove a course from course_plan
 */
void Student::drop(const int code)
{
    if (this->course_plan->search(code)!=NULL){
        this->course_plan->remove(code);
    }
}


/* TODO: Select courses with course_code larger than base from course_plan
 * Remark: Print the selected courses in ascending order of the course codes
 */
void Student::select_by_code(int base)
{
    cout << "Student ID: " << id << endl;

    if (this->course_plan==NULL)
        return;

    this->course_plan->iterator_init();
    while (!this->course_plan->iterator_end()){
        Course temp = this->course_plan->iterator_next();
        if (temp.get_code()>base){
            cout << temp << endl;
        }
    }


}

/* TODO: Select courses that have lectures on day from the course_plan
 * Remark: Print the selected courses in ascending order of the course codes
 */
void Student::select_by_day(weekday day)
{
    cout << "Student ID: " << id << endl;

    //Try to use the iterator??
    this->course_plan->iterator_init();
    while (!this->course_plan->iterator_end()){
        Course temp = this->course_plan->iterator_next();
        if (temp.get_time().match(day)){
            cout << temp << endl;
        }
    }
}

/* TODO: Check the details of an enrolled course
 * Remark: Print an appropriate message if the course is not in the course plan
 */
void Student::check_course(int code) const
{
    this->course_plan->iterator_init();
    while (!this->course_plan->iterator_end()){
        Course* temp = &this->course_plan->iterator_next(); 
        if (temp->get_code() == code){
            cout <<*temp<<endl;
            return;
        }
    }
    cout << "No"<<endl;



}



/* TODO: Print all courses students plan to take
 * Remark: Print the courses stored in the BT in preorder format
 */
void Student::list_course_plan() const
{
    cout << "Student ID: " << id << endl;
    if (this->course_plan!=NULL)
        this->course_plan->preorder_traversal();

}

/* Print course_plan in a readable tree format.
 * DON'T MODIFY THIS FUNCTION
 */
void Student::print_course_plan_tree() const
{
    cout << "Student ID: " << id << endl;
    course_plan->print();
}
