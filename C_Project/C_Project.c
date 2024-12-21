/*
 * C_Project.c
 *
 *  Created on: Aug 12, 2024
 *      Author: MOH
 */
#include <stdio.h>
#include <stdlib.h>
struct student{
	int id;
	char name[50];
	int age;
	float gpa;
};
struct node {
	struct student data;
	struct node *next;
};
struct node *head = NULL;
void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
int main(void){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i=0,c;
	while(i!=1){
		printf("-------------------------\n");
		printf("1. Add a Student\n");
		printf("2. Display All Students\n");
		printf("3. Search for a Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete a Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Find Student with Highest GPA\n");
		printf("8. Exit\n");
		printf("Enter choice: \n");
		scanf("%i",&c);
		printf("-------------------------\n");
		switch(c){
		case 1: {
					struct student data;
					printf("Enter new id: ");
					scanf("%i",&data.id);
					printf("Enter new name: ");
					scanf("%s",data.name);
					printf("Enter new age: ");
					scanf("%i",&data.age);
					printf("Enter new gpa: ");
					scanf("%f",&data.gpa);
					addStudent(&data);
					break;
				}
		case 2:{
			displayStudents();
			break;
		}
		case 3:{
			int t;
			printf("Enter student id");
			scanf("%i",&t);
			searchStudentByID(t);
			break;
				}
		case 4:{
					int t;
					printf("Enter student id: ");
					scanf("%i",&t);
					updateStudent(t);
					break;
						}
		case 5:{
							int t;
							printf("Enter student id: ");
							scanf("%i",&t);
							deleteStudent(t);
							break;
								}

		case 6:{
			printf("\nAverage GPA = %.2f\n",calculateAverageGPA());
			break;
				}
		case 7:{
			searchHighestGPA();
			break;
		}

		case 8:{
			i=1;
			printf("\nProgram Exit\n");
			break;
		}
		default:{
			printf("\nInvalid input\n");
			break;
		}
		return 0;
		}

	}
}
void addStudent(const struct student *const ptr){
	struct node *current = NULL;
	struct node *link =(struct node*)malloc(sizeof(struct node));
	if(link == NULL){
		printf("\n ERROR \n");
				return;
	}
	link->data=*ptr;
	link->next=NULL;
	if (head==NULL){
		head=link;
		return;
	}
	current = head;
	while(current->next!=NULL){
		if(ptr->id!=current->data.id){
			current=current->next;
		}
		else{
			printf("\n Student already exists \n");
			free(link);
			return;
		}
	}
	if(ptr->id==current->data.id){
				return;
			}

	current->next=link;
}
void displayStudents(void){
	if(head==NULL){
		printf("\n There is no students \n");
		return;
	}
	struct node *current = head;
	while(current!=NULL){
		printf(" Student id = %i\n",current->data.id);
		printf(" Student name = %s\n",current->data.name);
		printf(" Student age = %i\n",current->data.age);
		printf(" Student gpa = %.2f\n",current->data.gpa);
		printf("-------------------------\n");
		current = current->next;
	}
}
void searchStudentByID(int id){
	struct node *current = head;
	while(current!=NULL){
		if(current->data.id==id){
			printf(" Student id = %i\n",current->data.id);
			printf(" Student name = %s\n",current->data.name);
			printf(" Student age = %i\n",current->data.age);
			printf(" Student gpa = %.2f\n",current->data.gpa);
			return;
		}
		current = current-> next;
	}
	printf(" \n Student not found\n");

}
void updateStudent(int id){
	struct node *current = head;
		while(current!=NULL){
			if(current->data.id==id){
				printf("Enter new name: ");
				scanf("%s",current->data.name);
				printf("Enter new age: ");
				scanf("%i",&current->data.age);
				printf("Enter new gpa: ");
				scanf("%f",&current->data.gpa);
				return;
			}
			current = current-> next;
		}
		printf(" \n Student not found");
}
float calculateAverageGPA(void){
	struct node *current = head;
	if (head==NULL){
			return 0.0;
		}
	float c=0.0 , SumGpa=0.0;
	while(current!=NULL){
				c++;
				SumGpa+=current->data.gpa;
			    current = current-> next;
		}
	return SumGpa/c;
}
void searchHighestGPA(void){
	struct node *current = head;
	struct node *HighGpa = head;
	if (head==NULL){
			printf("There are no students. ");
			return;
		}
	float MaxGpa=head->data.gpa;
	while(current!=NULL){
		if(current->data.gpa>MaxGpa){
			HighGpa=current;
			MaxGpa=current->data.gpa;
		}
		current = current->next;
	}
	printf(" Student id with the highest gpa = %i\n",HighGpa->data.id);
	printf(" Student name = %s\n",HighGpa->data.name);
	printf(" Student age = %i\n",HighGpa->data.age);
	printf(" Student gpa = %.2f\n",HighGpa->data.gpa);
}
void deleteStudent(int id){
	struct node *current = head->next;
	struct node *prev = head;
	struct node *delete = NULL;
	if(head==NULL)
		{
			printf("There is no students");
			return;
		}
	if(head->data.id ==id )
		{
			delete = head;
			head = head->next;
			printf("delete was done successfully\n");
			free(delete);
			return;
		}
	while(current!=NULL){
		if(current->data.id==id){
			delete=current;
			prev->next=current->next;
			free(delete);
			printf("delete was done successfully\n");
			return;
		}
		prev=current;
		current=current->next;
	}
	if(delete == NULL)
		{
			printf("Student was not found.");
		}
}

