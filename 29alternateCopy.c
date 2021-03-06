#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
void createNode(struct node**);
void LLCopy(struct node**,struct node**);
void display(struct node*);
int count(struct node*);
int sortDsc(struct node**);
int copyDsc(struct node**,struct node**);
int listReverse(struct node**);
int loopCheck(struct node* );
int altCopy(struct node**,struct node**);

int main(){
	int itr1,num;
	struct node* src=NULL;
	struct node* dest=NULL;
	printf("Enter no. of nodes to be created.\n");
	scanf("%d",&num);
	for(int itr1=0;itr1<num;itr1++){
		createNode(&src);
	}
	printf("Source Linked List: ");
	display(src);
	printf("Enter no. of nodes to be created.\n");
	scanf("%d",&num);
	for(int itr1=0;itr1<num;itr1++){
		createNode(&dest);
	}
	printf("Dest Linked List: ");
	display(dest);
	altCopy(&src,&dest);
	display(src);
	return 0;
}

int altCopy(struct node** h1,struct node** h2){
	struct node* temp1=*h1;
	struct node* temp2=*h2;
	struct node* cur1=NULL;
	struct node* cur2=NULL;
	int cnt=1;
	if(*h1==NULL && *h2==NULL){
		printf("one of the list is empty.\n");
		return -1;
	}else{
		while(temp1!=NULL || temp2!=NULL){
			cur1=temp1->next;
			temp1->next=temp2;
			temp2=temp2->next;
			temp1->next->next=cur1;
			temp1=temp1->next->next;
		}
	}
}	

int loopCheck(struct node* src){
	if(src!=NULL){
	struct node* temp1=src;
	struct node* temp2=(src)->next;
		while(temp1!=temp2){
			temp1=temp1->next;
			temp2=temp2->next->next;
		}
		if(temp1==temp2){
			printf("Loop at %d\n",temp1->data);
		}
	}else{
		printf("List is empty.\n");
		return -1;
	}
	return 0;
}

int listReverse(struct node** head){
	struct node* cur=*head;
	struct node* prev=NULL;
	struct node* next=NULL;
	if(*head!=NULL){
		while(cur->next!=NULL){
			next=cur->next;
			cur->next=prev;
			prev=cur;
			cur=next;
		}
		cur->next=prev;
		*head=cur;
	}else{
		printf("List is empty.\n");
		return -1;
	}
	return 0;
}

int copyDsc(struct node **src,struct node** dest){
	if(*src==NULL){
		printf("No linked list to copy.\n");
		return -1;
	}else{
		LLCopy(src,dest);
		sortDsc(dest);
	}
	return 0;
}

int sortDsc(struct node** src){
	struct node* temp1=*src;
	struct node* temp2=*src;
	int data;
	while(temp1->next!=NULL){
		temp2=*src;
		while(temp2->next!=NULL){
			if(temp2->data<temp2->next->data){
				data=temp2->data;
				temp2->data=temp2->next->data;
				temp2->next->data=data;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}
void LLCopy(struct node **src,struct node **dest){
	struct node *stemp,*dtemp;
	stemp=*src;
	dtemp=*dest;
	struct node *newNode=NULL;
	while(stemp!=NULL){
		dtemp=*dest;
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=stemp->data;
		newNode->next=NULL;
		if(*dest==NULL){
			*dest=newNode;
		}else{
			while(dtemp->next!=NULL){
				dtemp=dtemp->next;
			}
			dtemp->next=newNode;
		}
		stemp=stemp->next;
	}
}
void display(struct node *head){
	struct node *temp=head;
	if(head==NULL){
		printf("List is empty.\n");
		return;
	}
	printf("OUTPUT: \n");
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|\n",temp->data);
}
void createNode(struct node **head){
	struct node *temp=*head;
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}
int count(struct node *head){
	struct node *temp=head;
	int cnt=1;
	if(head==NULL){
		return 0;
	}
	while(temp->next!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}

