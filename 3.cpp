//Вариант 6 задача 5

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student
{
    std::string first_name;
    std::string last_name;
    short average_mark = 0;
    short course = 0;
};

auto get_students_count()
{
    auto count = 0;
    std::cout << "enter students count:";
    std::cin >> count;
    std::cout << "\n";;
    return count;
}

Student get_students_data(auto *i)
{
    Student student_variable;
    std::cout <<"enter student #" << *i << " first name:";
    std::cin >> student_variable.first_name;
    std::cout << "\n";
    std::cout <<"enter student #" << *i << " last name:";
    std::cin >> student_variable.last_name;
    std::cout << "\n";
    std::cout <<"enter student #" << *i << " average mark:";
    std::cin >> student_variable.average_mark;
    std::cout << "\n";
    std::cout <<"enter student #" << *i << " course:";
    std::cin >> student_variable.course;
    std::cout << "\n";
    return student_variable;
}

void write_student_data_to_file(std::vector<Student> &students, auto const *students_count)
{
    std::ofstream out("out.txt", std::ios::app);
    for(auto i = 0; i<*students_count; i++)
    {
        out << "Name is:" << students[i].first_name << "\n" << "Last name is:"
        << students[i].last_name << "\n" << "Average mark is:" << students[i].average_mark << "\n" << "Course is:" << students[i].course << "\n" << "\n";
    }
}

void write_students_data_to_vector(std::vector<Student> &students, auto const *students_count)
{
    Student student_variable;
    for(auto i = 0; i<*students_count; i++)
    {
        student_variable = get_students_data(&i);
        students.push_back(student_variable);
    }
}

int main() {
    auto const students_count = get_students_count();
    std::vector<Student> students;
    write_students_data_to_vector(students, &students_count);
    write_student_data_to_file(students, &students_count);
}
