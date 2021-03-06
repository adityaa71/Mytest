#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;	
};

int insertFirst(struct node**,int);
struct node* newNode(int);
void display(struct node**);
int insertLast(struct node**,int);
int insertAtPos(struct node**,int,int);
int deleteFirst(struct node **);
int deleteLast(struct node **);

int main(){
	struct node* head=NULL;
	int itr1=0,num,no;
	printf("How many nodes to be created.\n");
	scanf("%d",&num);

	for(itr1=0;itr1<num;itr1++){
		printf("Element no. %d :",itr1+1);
		scanf("%d",&no);
		insertLast(&head,no);
	}
	display(&head);
	deleteLast(&head);	
	display(&head);	
	return 0;
}

int deleteLast(struct node** Head){
	struct node* temp=*Head;
	if(*Head==NULL){
		printf("List does not exist.\n");
		return -1;
	}	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->prev->next=NULL;
	temp->prev=NULL;
	free(temp);
	temp=NULL;
	return 0;
}

int deleteFirst(struct node** Head){
	struct node* temp=*Head;
	if(*Head==NULL){
		printf("Nothing to delete.\n");
		return -1;
	}
	*Head=(*Head)->next;
	(*Head)->prev=NULL;
	free(temp);
	temp=NULL;
	return 0;
}

int insertAtPos(struct node** Head,int no,int pos){
	struct node * temp=*Head;
	struct node * tNew=NULL;
	if(*Head==NULL){
		printf("List is empty.\n");
		return -1;
	}
	if(pos==1){
		insertFirst(Head,no);
	}else{
		while(pos-1>1){
			temp=temp->next;
			pos--;
		}
		tNew=newNode(no);
		tNew->next=temp->next;
		tNew->prev=temp;
		tNew->next->prev=tNew;
		temp->next=tNew;
	}

}

int insertLast(struct node** Head,int no){
	struct node *temp=*Head;
	if(*Head==NULL){
		temp=newNode(no);
		*Head=temp;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode(no);
		temp->next->prev=temp;
	}
}
int insertFirst(struct node** Head,int no){
	struct node* temp=NULL;
	if(*Head==NULL){
		temp=newNode(no);
		*Head=temp;
	}else{
		temp=newNode(no);
		temp->prev=NULL;
		temp->next=*Head;
		temp->next->prev=temp;
		*Head=temp;		
	}
}

struct node* newNode(int no){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Was not able to allocate memory.\n");
		return 0;
	}
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=no;
	return temp;
}

void display(struct node** Head){
	struct node *temp=*Head;
	if(*Head==NULL){
		printf("Nothing to display.\n");
		return;
	}else{
		while(temp->next!=NULL){
			printf("|%d|<=>",temp->data);
			temp=temp->next;
		}
		printf("|%d|\n",temp->data);
	}
}
