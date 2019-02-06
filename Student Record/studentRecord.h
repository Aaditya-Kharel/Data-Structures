#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include<iostream>
#include <string>
#include "courseDetailNode.h"

//using namespace std;
class studentRecord {
public:
    studentRecord(const std::string& name, const double& gpa, studentRecord* sr) {
        studentName = name;
        GPA = gpa;
        student_link = sr;
        
    }
    
    //Setters
    void set_studentName(const std::string& name) {
        studentName = name;
    }
    void set_student_link(studentRecord* student_ptr) {
        student_link = student_ptr;
    }
    void set_course_link(courseDetailNode* course_ptr) {
        course_link = course_ptr;
    }
    void set_GPA(const double& gpa) {
        GPA = gpa;
    }
    //Getters
    std::string get_studentName() const {
        return studentName;
    }
    studentRecord* get_student_link() const{
        return student_link;
    }
    courseDetailNode* get_course_link() const {
        return course_link;
    }
    double get_gpa() const {
        return GPA;
    }
    //a public variable that connects student record and coursedetail
    courseDetailNode* course_link=NULL;
private:
    std::string studentName;
    double GPA;
    studentRecord* student_link;
    
};

//TOOLKIT FOR studentRecord
void head_insert(const std::string& name, const double& gpa, studentRecord*& student_head_ptr) {
    student_head_ptr = new studentRecord(name, gpa, student_head_ptr);
}

void head_remove(studentRecord*& head_ptr) {
    studentRecord* remove_ptr;
    remove_ptr = head_ptr;
    head_ptr = head_ptr->get_student_link();
    delete remove_ptr;
}

int locate_position(studentRecord* head_ptr, std::string target) {
    int position = 0;
    studentRecord* cursor;
    for (cursor = head_ptr; head_ptr != NULL; cursor = cursor->get_student_link()) {
        ++position;
        if (cursor->get_studentName() == target) {
            return position;
            break;
        }
    }
    return position;
}

studentRecord* locate_previous_ptr(studentRecord* head_ptr, std::string target) {
    int prev_pos = (locate_position(head_ptr, target) - 1);
    studentRecord* cursor = head_ptr;
    for (int i = 1; (i < prev_pos) && (cursor != NULL); ++i) {
        cursor = cursor->get_student_link();
    }
    return cursor;
    
}

void list_remove(studentRecord* head_ptr, std::string target) {
    studentRecord* remove_ptr;
    studentRecord* previous_ptr;
    previous_ptr = locate_previous_ptr(head_ptr, target);
    remove_ptr = previous_ptr->get_student_link();	//catch the address of the node to be removed
    previous_ptr->set_student_link(remove_ptr->get_student_link());  //re-assign previous node's link_field
    delete remove_ptr;
}

void list_remove_studentRecord_any(studentRecord*& head_ptr, const std::string& target){
    if(head_ptr->get_studentName()==target){
        head_remove(head_ptr);
        
    }else{
        list_remove(head_ptr, target);
    }
}

//Function to insert the course at the head of the courseDetailNode of the desired student
void head_insert_master(const std::string& studentname, const std::string& courseName, const int& unit, const char& grade, studentRecord*& student_head_ptr) {
    studentRecord* cursor;
    
    for (cursor = student_head_ptr; cursor != NULL; cursor = cursor->get_student_link()) {
        if (cursor->get_studentName() == studentname) {
            head_insert(courseName, unit, grade, cursor->course_link);
            //std::cout<<"After Head Insert"<<std::endl;
            //std::cout << "master head insertion test" << std::endl;
        }
        //break;
    }
}

//Function that prints the all the list of students
void printCourse_master(const studentRecord* head_ptr) {
    const studentRecord* cursor;
       for (cursor = head_ptr; cursor != NULL; cursor = cursor->get_student_link()) {
           std::cout<<std::endl;
        std::cout << cursor->get_studentName() << std::endl;
        //std::cout << cursor->get_gpa()<< std::endl;
        printCourse(cursor->course_link);
        // std::cout<<"print master test"<<std::endl;
    }
    std::cout<<std::endl;
}

//Function to remove a course at the head of the list of courseDetailNode of a desired student
void head_remove_master(studentRecord*& head_ptr, const std::string& studentname) {
    studentRecord* cursor;
    
    for (cursor = head_ptr;cursor != NULL; cursor = cursor->get_student_link()) {
        if (cursor->get_studentName() == studentname) {
            head_remove(head_ptr->course_link);
        }
    }
}


//Function to remove course of courseNodeDetail other than head_remove of a desired student
void list_remove_master(studentRecord* head_ptr, std::string studentName, std::string course_target) {
    studentRecord* cursor;
    
    for (cursor = head_ptr;cursor != NULL; cursor = cursor->get_student_link()) {
        if (cursor->get_studentName() == studentName) {
            list_remove(head_ptr->course_link, course_target);
        }
    }
}

//Function that removes a desired course for a courseDetailNode at any location of a desired sudent
void list_remove_any(studentRecord* head_ptr, std::string studentName, std::string course_target) {
    studentRecord* cursor;
    
    for (cursor = head_ptr;cursor != NULL; cursor = cursor->get_student_link()) {
        if (cursor->get_studentName() == studentName) {
            if (cursor->course_link->get_courseName() == course_target) {
                head_remove(cursor->course_link);
            }
            else {
                list_remove(head_ptr->course_link, course_target);
            }
        }
    }
}

#endif

