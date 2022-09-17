#include <iostream>

using namespace std;

class Student
{
private:
	int rollNo;
	string name;

public:
	// Student(){
	// 	cout<<"simple constructor is called"<<endl;
	// }

	static int schoolId;

	static int giveSchoolId()
	{
		// static function can only access static variables in this class
		return schoolId;
	}

	Student(int rollNo = 0)
	{
		this->rollNo = rollNo;
	}

	Student(Student &S)
	{
		cout << "custom copy constructor/assignment-operator called (deep copy)" << endl
			 << endl;
		this->rollNo = S.rollNo;
		this->name = S.name;
	}

	Student(int rollNo, string name)
	{
		this->rollNo = rollNo;
		this->name = name;
	}

	int rollGetter()
	{
		return rollNo;
	}

	string nameGetter()
	{
		return name;
	}

	void setter(string n = NULL, int r = 0)
	{
		rollNo = (r) ? r : rollNo;
		name = (n.size()) ? n : name;
	}

	~Student()
	{
		cout << "Destructor called" << endl
			 << endl;
	}
};

int Student::schoolId = 1911;

int main()
{
	Student s1(10);
	s1.setter("ramesh");
	cout << "s1-> " << s1.nameGetter() << " " << s1.rollGetter() << endl
		 << endl;

	Student *s2 = new Student;
	s2->setter("prayas", 23);
	cout << "s2-> " << s2->nameGetter() << " " << s2->rollGetter() << endl
		 << endl;

	Student s3(*s2);
	cout << "s3-> " << s3.nameGetter() << " " << s3.rollGetter() << endl
		 << endl;
	delete s2;

	Student s4 = s1;
	cout << "s4-> " << s4.nameGetter() << " " << s4.rollGetter() << endl
		 << endl;

	cout << "Calling static member variable " << Student::schoolId << endl
		 << endl;

	cout << "Calling static member function " << Student::giveSchoolId() << endl
		 << endl;

	return 0;
}