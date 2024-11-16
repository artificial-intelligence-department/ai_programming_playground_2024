#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string.h>

struct Student
{
    char p[100], i[100], b[100], phone_number[15], group[6];
    int grades[3];
};

void print_student(const Student& s)
{
    std::cout << "PIB: " << s.p << " " << s.i << " " << s.b << std::endl
        << "Phone: " << s.phone_number << std::endl
        << "Group: " << s.group << std::endl
        << "Grades: " << s.grades[0] << " " << s.grades[1] << " " << s.grades[2] << std::endl;
}

Student create_student_from_stdin()
{
    Student s;
    std::cout << "Enter prizvishe: ";
    std::cin >> s.p;
    std::cout << "Enter name: ";
    std::cin >> s.i;
    std::cout << "Enter pobatkovi: ";
    std::cin >> s.b;
    std::cout << "Enter phone number: ";
    std::cin >> s.phone_number;
    std::cout << "Enter group: ";
    std::cin >> s.group;
    std::cout << "Enter grades 1, 2, 3: ";
    std::cin >> s.grades[0] >> s.grades[1] >> s.grades[2];
    return s;
}

void write_to_file(const std::string filename, const std::vector<Student>& data, bool truncate = true)
{
    std::fstream fs;
    fs.open(filename, std::fstream::out | std::fstream::binary | (truncate ? std::fstream::trunc : std::fstream::app));
    if (!fs) 
    {
        std::cout << "Cannot open file for writing." << std::endl;
        return;
    }
    
    for (const Student& s : data)
    {
        fs.write(reinterpret_cast<const char *>(&s), sizeof(Student));
    }

    fs.close();
}

void print_from_file(const std::string filename)
{
    std::fstream fs;
    fs.open(filename, std::fstream::in | std::fstream::binary);
    if (!fs) 
    {
        std::cout << "Cannot open file for reading." << std::endl;
        return;
    }

    Student s;
    while (fs.read(reinterpret_cast<char*>(&s), sizeof(Student))) print_student(s);
    fs.close();
}

void delete_from_group_by_mean(const std::string filename, const char* group, double mean)
{
    std::fstream fs;
    fs.open(filename, std::fstream::in | std::fstream::binary);
    if (!fs) 
    {
        std::cout << "Cannot open file for reading." << std::endl;
        return;
    }

    std::vector<Student> students;
    Student s;
    while (fs.read(reinterpret_cast<char*>(&s), sizeof(Student))) students.push_back(s);
    fs.close();

    for (auto i = students.begin(); i != students.end(); )
    {
        if (!strcmp(i->group, group) && mean > (i->grades[0]+i->grades[1]+i->grades[2])/3.0) 
            i = students.erase(i);
        else
            i++;
    }
    
    write_to_file(filename, students);
}

void append_after_p(const std::string filename, const char* p)
{
    std::fstream fs;
    fs.open(filename, std::fstream::in | std::fstream::binary);
    if (!fs) 
    {
        std::cout << "Cannot open file for reading." << std::endl;
        return;
    }

    std::vector<Student> students;
    Student s;
    while (fs.read(reinterpret_cast<char*>(&s), sizeof(Student))) students.push_back(s);
    fs.close();

    for (auto i = students.begin(); i != students.end(); i++)
    {
        if (!strcmp(i->p, p))
        {
            s = create_student_from_stdin();
            students.insert(i, s);
            break;
        }
    }
    
    write_to_file(filename, students);
}

int main()
{
    std::stringstream filename_ss;
    filename_ss << "lab8_" << time(0) << ".dat";
    const std::string filename = filename_ss.str();
    std::cout << "Filename: " << filename << std::endl;

    std::vector<Student> students;
    int size;
    std::cout << "Enter size of vector: ";
    std::cin >> size;

    for(int i = 0; i < size; i++)
    {
        students.push_back(create_student_from_stdin());
    }

    write_to_file(filename, students);
    print_from_file(filename);

    char group[6];
    double mean;
    std::cout << "Enter group and minimum mean: ";
    std::cin >> group >> mean;
    delete_from_group_by_mean(filename, group, mean);
    print_from_file(filename);

    char p[100];
    std::cout << "Enter prizvishe: ";
    std::cin >> p;
    append_after_p(filename, p);
    print_from_file(filename);
}
