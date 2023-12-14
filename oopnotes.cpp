#include <iostream>
using std::string;


class AbstractEmployee{
    virtual void AskForPromotion() = 0;


};


class Employee:AbstractEmployee {
private:

    string Name;
    string Company;
    int Age;




public:
//setter
    void setName(string name)
    {
        Name = name; 
    }
//getter
    string getName(){
        return Name;
    }

    void setCompany(string company){
        Company = company;
    }

    string getCompany()
    {
        return Company;
    }

    void setAge(int age)
    {
        if(age >= 18)
        Age = age;
    }

    int getAge(){
        return Age;
    }


    void IntroduceYourself(){
        std::cout << "Name - " << Name << std::endl;
        std::cout<< " Company - " << Company << std::endl;
        std::cout << "Age " << Age << std::endl;
        std::cout << std::endl;



    }

    //constructor
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;

    }
    
    
    void AskForPromotion()
    {
        if (Age > 30)
        std::cout<<Name<<" got promoted! " << std::endl;
        else 
        std::cout<<Name<< " , sorry NO promotion for you! " <<std::endl;
    }


    //virtual means that it will check if there is a implimentation in derived classes if so it will use that 
    //implimentation instead. if no then it wont, and instead will just use the implimentation in this base class 
    //employee
    virtual void Work()
    {
        std::cout<<Name<<" is checking email, task backlog, performing tasks... " <<std::endl;
    }

};
//the : means that the develop inhereits all the attributes of employee. Developer is the child class, and Employee is a super/parent class

class Developer:public Employee {
    public:
    string FavProgLang;



    Developer(string name, string company, int age, string favprogramminglanguage):Employee(name, company, age)
    {
        FavProgLang = favprogramminglanguage;
    }

    void FixBug()
    {
        std::cout<<getName()<<" fixed bug using " << FavProgLang << std::endl;

    }

        void Work()
    {
        std::cout<<getName()<< "is writing " << FavProgLang <<std::endl;
    }


};
class Teacher:public Employee{
    public:
    string Subject;

    void PrepareLesson(){
        std::cout<<getName()<<" is preparing " << Subject << "lesson"<<std::endl;
    }

    Teacher(string name, string company, int age, string subject):Employee(name, company, age)
    {
        Subject = subject;
    }

     void Work()
    {
        std::cout<<getName()<< "is teaching " << Subject <<std::endl;
    }

};


int main ()
{

//settting employee1 as type employee



    Developer d = Developer("Saldina","YT-CODE BEAUTY", 25, "C++");
    Teacher t = Teacher("Jack", "Cool School", 35 ,"History");
    
    //A base class pointer to a derived class objected, .work must be Virtual otherwise you'll just get the work function from the parent class employee
    Employee *e1 = &d;
    Employee *e2 = &t;




    e1->Work();
    e2->Work();



}