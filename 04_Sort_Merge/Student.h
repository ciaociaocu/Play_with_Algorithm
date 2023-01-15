#ifndef _STUDENT_H
#define _STUDENT_H

#include<iostream>
#include<string>

struct Student
{
	std::string name;
	int score;
	
	bool operator<(const Student& otherStudent)
	{
		return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const Student& student)
	{
		os<<"Student: "<<student.name<<" "<<student.score<<std::endl;
		return os;
	}
};
#endif