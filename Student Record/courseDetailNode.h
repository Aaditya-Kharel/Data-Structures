#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstdlib>
#include <string>


//Course Detail Nodes
class courseDetailNode {
    
public:
    //CONSTRUCTOR
    courseDetailNode(std::string name, int unit, char grade, courseDetailNode* ptr) {
        courseName = name;
        creditHours = unit;
        courseGrade = grade;
        link_field = ptr;
    }
    
    //In-line Setters
    void set_courseName(const std::string& new_courseName) {
        courseName = new_courseName;
    }
    void set_creditHour(const int& new_creditHour) {
        creditHours = new_creditHour;
    }
    void set_courseGrade(const int& new_courseGrade) {
        courseGrade = new_courseGrade;
    }
    void set_link(courseDetailNode* new_link_field) {
        link_field = new_link_field;
    }
    //In-line const Getters memeber functions
    std::string get_courseName() const {
        return courseName;
    }
    int get_creditHour() const {
        return creditHours;
    }
    char get_courseGrade() const {
        return courseGrade;
    }
    courseDetailNode* get_link_field() const {
        return link_field;
    }
    //~courseDetailNode() {
    //	delete link_field;
    //}
private:
    std::string courseName;
    int creditHours;
    char courseGrade;
    //double GPA = 0.0;
    courseDetailNode* link_field;
};

// HELPER FUNCTIONS/LINKED LIST TOOLKIT for courseDetailNode class
void head_insert(const std::string& cn, const int& ch, const char& cg, courseDetailNode*& head_ptr)
{
    head_ptr = new courseDetailNode(cn, ch, cg, head_ptr);
    //std::cout<<head_ptr->get_courseName()<<" "<<head_ptr->get_creditHour()<<" "<<head_ptr->get_courseGrade()<<std::endl;
}

void head_remove(courseDetailNode*& head_ptr) {
    courseDetailNode* remove_ptr;
    remove_ptr = head_ptr;
    head_ptr = head_ptr->get_link_field();
    delete remove_ptr;
}

void printCourse(const courseDetailNode* head_ptr) {
    const courseDetailNode* cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->get_link_field()) {
        std::cout << cursor->get_courseName() <<" ";
        std::cout << cursor->get_creditHour() <<" ";
        std::cout << cursor->get_courseGrade() << std::endl;
    }
}

int locate_position(courseDetailNode* head_ptr, std::string target) {
    int position = 0;
    courseDetailNode* cursor;
    for (cursor = head_ptr; head_ptr != NULL; cursor = cursor->get_link_field()) {
        ++position;
        if (cursor->get_courseName() == target) {
            return position;
            break;
        }
    }
    return position;
}

courseDetailNode* locate_previous_ptr(courseDetailNode* head_ptr, std::string target) {
    int prev_pos = (locate_position(head_ptr, target) - 1);
    courseDetailNode* cursor = head_ptr;
    for (int i = 1; (i < prev_pos) && (cursor != NULL); ++i) {
        cursor = cursor->get_link_field();
    }
    return cursor;
    
}

void list_remove(courseDetailNode* head_ptr, std::string target) {
    courseDetailNode* remove_ptr;
    courseDetailNode* previous_ptr;
    previous_ptr = locate_previous_ptr(head_ptr, target);
    remove_ptr = previous_ptr->get_link_field();	//catch the address of the node to be removed
    previous_ptr->set_link(remove_ptr->get_link_field());  //re-assign previous node's link_field
    delete remove_ptr;
}



#endif

