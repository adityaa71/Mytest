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
struct node* listReverse(struct node**);
int loopCheck(struct node* );
int altCopy(struct node**,struct node**);
int swap(struct node**);
int insertAtList(struct node**,struct node**,int);
int listRevRange(struct node**,int,int);
int listPalindrome(struct node**);

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
	int res=listPalindrome(&src);
	if(!res){
		printf("List is palindrome.\n");
	}else{
		printf("List is palindrome.\n");
	}
	return 0;
}

int listPalindrome(struct node** src){
	struct node* temp1=*src;
	int len=0,itr1=0,itr2=0;
	if(*src!=NULL){
	len=count(*src);
	int arr[len];
	while(temp1!=NULL){
		arr[itr1]=temp1->data;
		temp1=temp1->next;
		itr1++;
	}
	itr1--;
	while(itr1!=itr2){
		if(arr[itr1]!=arr[itr2]){
			return -1;
		}
		if(itr2<itr1){
			break;
		}
		itr2++;
		itr1--;
	}
	}else{
		printf("list is empty.\n");
		return -1;
	}
	return 0;
}

int listRevRange(struct node** src,int start,int end){
	struct node* temp1=*src;
	struct node* temp2=NULL;
	struct node* temp3=NULL;
	struct node* temp4=NULL;
	struct node* temp5=NULL;
	int cnt=1;
	while(cnt<=end){
		if(cnt<start){
			temp4=temp1;
		}
		if(cnt==start){
			temp2=temp1;
			printf("%d\n",temp2->data);
		}
		if(cnt==end){
			temp3=temp1;
			temp5=temp1->next;
			printf("%d\n",temp3->data);
		}	
		temp1=temp1->next;
		cnt++;
	}
	temp3->next=NULL;
	temp4->next=listReverse(&temp2);
	while(temp4->next!=NULL){
		temp4=temp4->next;
	}
	temp4->next=temp5;
}

int insertAtList(struct node** src,struct node** dest,int pos){
	struct node *temp1=*src;
	struct node *temp2=*dest;
	struct node* temp=NULL;
	if(*src==NULL || *dest==NULL){
		printf("list is empty.\n");
		return -1;
	}else{
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		if(pos==1){
			temp=temp2;
			*dest=*src;	
		}else{
			while(pos-1>1){
				temp2=temp2->next;
				pos--;
			}
			temp=temp2->next;
			temp2->next=*src;
		}
		temp1->next=temp;
		return 0;
	}	
}

int swap(struct node** src){
	struct node* temp=*src;
	int data;
	while(temp!=NULL){
		if(temp->next==NULL){
			return 0;
		}
		data=temp->data;
		temp->data=temp->next->data;
		temp->next->data=data;
		temp=temp->next->next;
	}
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

struct node* listReverse(struct node** head){
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
		return NULL;
	}
	return (*head);
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

