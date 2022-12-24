/*2. Создать свой класс Lesson, в котором будут поля
const char* subject - название учебного предмета, например, С++,  UML, ...,
const char* teacher - Имя Фамилия преподавателя.
В нём обязательно должен быть явно заданный конструктор копирования.
В конце тела функции main продемонстрировать работу конструктора копирования
и результаты этой работы (вывести в консоль данные скопированного объекта).*/

#include <iostream>
using namespace std;

class Lesson {
	//поля
	const char* subject;
	const char* teacher;
public:
	// конструктор по умолчанию
	Lesson() {
		subject = nullptr;
		teacher = nullptr;
	}

	// конструктор копирования
	Lesson(Lesson& l) {
		this->subject = l.subject;
		this->teacher = l.teacher;
	}

	// сеттеры
	void setsubject(const char* subject) {
		this->subject = subject;
	}
	void setteacher(const char* teacher) {
		this->teacher = teacher;
	}

	// геттеры
	const char* getsubject() {
		return this->subject;
	}
	const char* getteacher() {
		return this->teacher;
	}
};

int main()
{
	Lesson l1;
	l1.setsubject("C++");
	l1.setteacher("John Smith");
	cout << "First lesson (object address: " << &l1 << ")\nSubject: " << l1.getsubject() << endl << "Teacher: " << l1.getteacher() << endl << endl;

	Lesson l2(l1);
	cout << "Second lesson copied (object address: " << &l2 << ")\nSubject: " << l2.getsubject() << endl << "Teacher: " << l2.getteacher() << endl << endl;

	l2.setsubject("UML");
	l2.setteacher("Mary Smith");
	cout << "Second lesson modified (object address: " << &l2 << ")\nSubject: " << l2.getsubject() << endl << "Teacher: " << l2.getteacher() << endl << endl;
}