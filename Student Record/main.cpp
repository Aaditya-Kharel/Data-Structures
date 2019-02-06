#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "studentRecord.h"
#include <fstream>
using namespace std;

void menuItem();

int main() {
    ifstream inFile;
    inFile.open("input.txt");    //opening file
    ofstream outFile;
    outFile.open("output.txt");
    
    studentRecord* head_ptr=NULL;   //pointer declaration for studentRecord
    
    string studentName="";             //studentName
    string courseName="";              //courseName
    int creditHours=0;                //credithours
    char grade=' ';                     //Grade
    int gpa=0;                     //GPA
    
    string line;
    
    while(std::getline(inFile,studentName)){
       // inFile>>gpa;
        //cout<<"Enter the Student GPA"<<endl;
        //cin>>gpa;
        head_insert(studentName, gpa, head_ptr);
        bool continueWithin=true;
        std::getline(inFile, courseName);
        while(continueWithin){
            inFile>>creditHours;
           // cout<<creditHours<<endl;
            inFile>>grade;
           // cout<<grade<<endl;
            
            head_insert_master(studentName, courseName, creditHours, grade, head_ptr);
            

            std::getline(inFile, line);
            
        
            int peekValue=inFile.peek();
            
            
            if(peekValue>=65&&peekValue<=90){
                
                continueWithin=true;
                
                std::getline(inFile,courseName);
                
            }
            
            else{
                
                continueWithin=false;
                
                std::getline(inFile, line);
                
            }
            
        }
    }
    
    do{
        
        cout<<"Enter 1 to add a student record (ONLY ADDS A STUDENT NAME TO RECORD!)"<<endl;
        
        cout<<"Enter 2 to delete a student record (DELETES ALL COURSES TOO!)"<<endl;
        
        cout<<"Enter 3 to add course to a student record (ENTER WITHOUT SPACES!)(ADDS SPECIFIC COURSE TO EXISTING STUDENT!)"<<endl;
        
        cout<<"Enter 4 to delete a course from a student record (DELTES SPECIFIC COURSE OF EXISTING STUDENT!)"<<endl;
        
        cout<<"Enter 5 to print (PRINTS EXISTING RECORD FROM FILE)"<<endl;
        
        cout<<"Enter 6 to SAVE CHANGES TO FILE and EXIT SUCCESSFULLY"<<endl;
        
        int menu;
        cin>>menu;
        
        if(menu==1){
            cout<<"Enter the name of the student to add to the record"<<endl;
            cin.ignore();
            getline(cin, studentName);
            getline(inFile, studentName);
            head_insert(studentName, 4.0, head_ptr);
        }
        
        if(menu==2){
            cout<<"Enter the name of the student to delete record (NAME MUST MATCH THE NAME IN THE REOCRD"<<endl;
            cin.ignore();
            getline(cin, studentName);
            list_remove_studentRecord_any(head_ptr, studentName);
        }
        
        if(menu==3){
            cout<<"Enter the name of the desired student to enter the course (NAME MUST MATCH THE NAME IN RECORD)"<<endl;
            cin.ignore();
            getline(cin,studentName);
            cout<<"Enter the name of the course you want to add"<<endl;
            getline(cin, courseName);
            cout<<"Enter the credit hours of the course"<<endl;
            cin>>creditHours;
            cout<<"Enter the grade obatained in the course"<<endl;
            cin>>grade;
            head_insert_master(studentName, courseName, creditHours, grade, head_ptr);
        }
        
        
        if(menu==4){
            cout<<"Enter the name of the desired student to delete the course (NAME MUST MATCH THE NAME IN RECORD)"<<endl;
            cin.ignore();
            getline(cin,studentName);
            cout<<"Enter the name of the course that you want to delete"<<endl;
            getline(cin,courseName);
            list_remove_any(head_ptr, studentName, courseName);
        }
        
        if(menu==5){
            
            printCourse_master(head_ptr);
        }
        
        if(menu==6){
            studentRecord* cursor1;
            courseDetailNode* cursor2;
            for(cursor1=head_ptr; cursor1!=NULL; cursor1=cursor1->get_student_link()){
                outFile<<cursor1->get_studentName()<<endl;
                //outFile<<cursor1->get_gpa()<<endl;
                if((cursor1->course_link)!=NULL){
                    for(cursor2=cursor1->course_link; cursor2!=NULL; cursor2=cursor2->get_link_field()){
                        outFile<<cursor2->get_courseName()<<endl;
                        outFile<<cursor2->get_creditHour()<<endl;
                        outFile<<cursor2->get_courseGrade()<<endl;
                    }
                }
                outFile<<endl;
                
            }
            inFile.close();
            outFile.close();
            
            remove("input.txt");
            rename("output.txt","input.txt");
            break;
        
        }
        
        
    }while(true);
    
  
    
    return 0;
}
