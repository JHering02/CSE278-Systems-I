#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course
{
   // define operator<< as a friend function for Course
   friend std::ostream& operator<< (std::ostream& os, Course const& v);

   public:
       Course(const std::string& courseName, const std::string& section, size_t capacity);
        ~Course();
       // overload copy constructor
       Course(const Course& orig);
       // overload copy assignment operator
       Course& operator= (const Course& objCop);
       void setCourseName(std::string name);
       std::string getCourseName() const;
       void setSection(std::string section);
       std::string getSection() const;
       void addStudent(const std::string& name);
       void editStudent(size_t index,std::string newname);
       void dropStudent(const std::string& name);
       size_t getNumberOfStudents() const;
       size_t getCourseCapacity()const;
       void shrinkCapacity();
       void increaseCapacity(size_t inc);
       std::string getStudents(size_t index);
       //overload operator+= as a member function
       Course& operator+= (Course& cour1);
 private:
     std::string courseName;
     std::string section;
     std::string* students;
     size_t numberOfStudents;
     size_t capacity;
};

#endif
