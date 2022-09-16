#include <iostream>

using namespace std;

class Student
{
private:
	int rollNo;
	string name;

public:
	int rollGetter()
	{
		return rollNo;
	}
	string nameGetter()
	{
		return name;
	}
	void setter(int r, string n)
	{
		rollNo = r;
		name = n;
	}
};

int main()
{
	Student s1;
	s1.setter(22, "ramesh");
	cout << s1.nameGetter() << " " << s1.rollGetter() << endl;

	Student *s2 = new Student;
	s2->setter(23, "chomu");
	cout << s2->nameGetter() << " " << s2->rollGetter() << endl;
	return 0;
}