#include <iostream>

enum typePosition{
    Ceo,
    Manager
};

class SoftwareCompany{

};

class Workers{
protected:
   char* name;
   int salary;
public:
    void print() const{
        std::cout<<name<<" "<<salary;
    }

    virtual int getWorkersCounter() const = 0;

};

class Employee:public Workers{
public:
    int getWorkersCounter() const
    {
        return 0;
    }
};

class ContainerWorkers : public Workers
{
protected:
    Workers** workers;
    //...
    void print() const{
      for(int i = 0; i < 5; i++)
          workers[i]->print();
    }
};

class Manager : public ContainerWorkers
{
     typePosition poition;
public:

    int getWorkersCounter() const {


    }


    void addSubordinate(Employee* subordinate);

};




int main() {

}
