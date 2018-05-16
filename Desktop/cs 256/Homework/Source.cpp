#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
	friend class Parent;
	friend class Child;
private:
	string name;
	int age;
	char sex;
	Human();
public:
	void setName(string n) {
		name = n;
	}
	void setAge(int a) {
		age = a;
	}
	void setSex(char s) {
		sex = s;
	}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	char getSex() {
		return sex;
	}
	virtual string work();
protected:
	Human(string n, int a, char s) {
		name = n;
		a = age;
		s = sex;
	}
};

class Parent : public Human {
private:
	vector <Child> children;
public:
	void setChild(vector<Child> &x) {
		children = x;
	}
	vector<Child>& getChild() {
		return children;
	}
};

class Child : public Human {
	friend class parent;
private:
	Parent mom;
	Parent dad;
	Child();
public:
	Child(Parent m, Parent d) {
		mom = m;
		dad = d;
	}
};
int main() {
	//Create simpsons family
	Parent father;
	father.setName("Homer");
	father.setAge(36);
	father.setSex('M');
	Parent mother;
	mother.setName("March");
	mother.setAge(34);
	mother.setSex('F');


	Child son(father,mother);
	Child daughter1(father,mother);
	Child daughter2(father,mother);
	
	mother.setChild(daughter1);
	father.setChild(son);
	mother.setChild(daughter2);

	father.setName("Bart");
	father.setAge(10);
	father.setSex('M');
	
	mother.setName("Maggie");
	mother.setAge(3);
	mother.setSex('F');

	father.setName("Lisa");
	father.setAge(12);
	father.setSex('F');

	//Print out 
	cout << father.getName << "\t" <<
		father.getAge() << "\t" <<
		father.getSex()
		<< mother.getName << "\t" <<
		mother.getAge() << "\t" <<
		mother.getSex()
		<< son.getName << "\t" <<
		son.getAge() << "\t" <<
		son.getSex()
		<< daughter1.getName << "\t" <<
		daughter1.getAge() << "\t" <<
		daughter1.getSex()
		<< daughter2.getName << "\t" <<
		daughter2.getAge() << "\t" <<
		daughter2.getSex();

	return 0;
}