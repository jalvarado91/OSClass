/*##########################################################
## COP4610 – Principles of Operating Systems – Summer C 2017
## Prof. Jose F. Osorio
## Student: Juan Alvarado – 3367805
##
## Assignment #: 3
## Specs: Task 1.3, Scheduling Problem
## Due Date: 06/09/2017 by 11:55pm
##
## Module Name: task13
##
## I Certify that this program code has been written by me
## and no part of it has been taken from any sources.
##########################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// #include <pthread.h>
#include <semaphore.h>

int num_students;
int office_capacity;
int current_student_id;
int students_left;

sem_t OfficeSpots;
sem_t StudentCanAskQuestion;
sem_t ProfessorCanSpeak;
sem_t StudentCanSpeak;

void Professor();
void Student(int id);

void AnswerStart(int student_id);
void AnswerDone(int student_id);
void EnterOffice(int id);
void LeaveOffice(int id);
void QuestionStart(int id);
void QuestionDone(int id);

int main(int argc, char *argv[])
{
	// Input Validation
	if (argc <= 2)
	{
		printf("Error: Please specify a number of students and office capacity.\n");
		return 0;
	}

	num_students = atoi(argv[1]);
	office_capacity = atoi(argv[2]);
	if (!num_students || !office_capacity)
	{
		printf("Arguments are not valid.\n");
		return 0;
	}
	printf("num_students: %d, capacity: %d\n", num_students, office_capacity);

	sem_init(&OfficeSpots, 1, office_capacity);
	sem_init(&StudentCanAskQuestion, 1, 1);
	sem_init(&ProfessorCanSpeak, 1, 0);
	sem_init(&StudentCanSpeak, 1, 0);

	int tid;
	students_left = num_students;
	omp_set_num_threads(num_students + 1); // Reserve a thread for the professor
	
	#pragma omp parallel shared(current_student_id, students_left) private(tid)
	{
		tid = omp_get_thread_num();
		
		//Professor
		if (tid == 0) {
			Professor();
		} 
		// Student
		else {
			Student(tid - 1);
		}
	}

	printf("Simulation completed. No more students left.\n");
	return 0;

}

void Professor() {
	while(students_left > 0) {
		sem_post(&StudentCanSpeak);
		sem_wait(&ProfessorCanSpeak);
		AnswerStart(current_student_id);
		AnswerDone(current_student_id);
		sem_post(&StudentCanSpeak);
	}
}

void Student(int id) {
	int student_id = id;
	int n_questions = (student_id % 4) + 1;
	int quest;
	
	sem_wait(&OfficeSpots); // Wait for a spot in the office
	EnterOffice(student_id);

	for(quest = 0; quest < n_questions; quest++) {
		sem_wait(&StudentCanAskQuestion); // Wait for turn
		current_student_id = student_id;
		sem_wait(&StudentCanSpeak);
		QuestionStart(student_id);
		sem_post(&ProfessorCanSpeak); // Let professor answer

		sem_wait(&StudentCanSpeak);
		QuestionDone(student_id);

		sem_post(&StudentCanAskQuestion); // Let another student ask
	}

	students_left--;
	sem_post(&OfficeSpots); // Let another student in the office
	LeaveOffice(student_id); 	
	if(students_left == 0) {
		printf("Simulation completed. No more students left.\n");
		exit(0);
	}	
}

// Professor Actions
void AnswerStart(int student_id) {
	printf("Professor starts to answer question for student %d.\n", student_id);
}
void AnswerDone(int student_id) {
	printf("Professor is done with answer for student %d.\n", student_id);
}

// Student Actions
void EnterOffice(int id) {
	printf("Student %d enters the office.\n", id);
}
void LeaveOffice(int id) {
	printf("Student %d leaves the office.\n", id);
}
void QuestionStart(int id) {
	printf("Student %d asks a question.\n", id);
}
void QuestionDone(int id) {
	printf("Student %d is satisfied.\n", id);
}
