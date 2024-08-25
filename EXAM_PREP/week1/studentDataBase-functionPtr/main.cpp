#include <iostream>
#include <cstring>

enum class Major{
    undef,
    SI,
    CS,
    Inf,
};

struct Student{
    char name[1024];
    unsigned fn = 0;
    Major major = Major::undef;
};

struct StudentDataBase{
    unsigned countStudents = 0;
    Student students[25];
};

enum class Criteria{
    sortByFn,
    sortByName,
};

void sortByCriteria(StudentDataBase& dataBase, bool (*isLess)(const Student& s1, const Student& s2)){

    for(int i = 0; i <dataBase.countStudents - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < dataBase.countStudents ; j++)
        {
          if(isLess(dataBase.students[minIndex], dataBase.students[j]))
              minIndex = j;

          if(minIndex != i)
              std::swap(dataBase.students[i], dataBase.students[minIndex]);
        }
    }
}

void sortDataBaseByCriteria(StudentDataBase& dataBase, Criteria cr)
{
    switch (cr){
        case Criteria::sortByFn :
           return  sortByCriteria(dataBase, [](const Student& s1, const Student& s2){return s1.fn > s2.fn;});
        case Criteria::sortByName :
          return  sortByCriteria(dataBase, [](const Student& s1, const Student& s2){return strcmp(s1.name,s2.name)<0;});
    }
}

void printStudent(const Student& st)
{
    std::cout << st.name << " " << st.fn  << std::endl;
}
void printDatabase(const StudentDataBase& database)
{
    for (int i = 0; i < database.countStudents; i++)
        printStudent(database.students[i]);
}


int main() {

    StudentDataBase s =
            {
                    3,
                    {
                            {"Petur", 12, Major::Inf},
                            {"Ivan", 4, Major::CS},
                            {"Aleksandur", 56, Major::SI}
                    }
            };

    sortDataBaseByCriteria(s,Criteria::sortByFn);
    printDatabase(s);
}
