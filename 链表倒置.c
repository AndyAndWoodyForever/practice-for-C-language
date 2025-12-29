#include<stdio.h> 
#include<malloc.h>

struct intNode{
	int value;
	struct intNode *next;
};

struct intNode *reverse(struct intNode *h){
	struct intNode *p, *v1, *v2;
	v2=h;
	v1=NULL;
	while(v2!=NULL){
		p=v2->next;
		v2->next=v1;
		v1=v2;
		v2=p;
	}
	h=v1;
	return h;
}

struct intNode *createchain(int n){
	struct intNode *head, *p, *tail;
	int i=0;
	head=tail=NULL;
	for(;i<n;i++){
		p=(struct intNode *)malloc(sizeof(struct intNode));
		p->value=i+1;
		p->next=NULL;
		if(head==NULL) head=tail=p;
		else tail=tail->next=p;
	}
	return head;
}


void output(struct intNode *h){
	struct intNode *p=h;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}


void freeloop(struct intNode *h){
	struct intNode *p=h;
	for(;p;p=h){
		h=h->next;
		free(p);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	struct intNode *head=createchain(n);
	output(head);
	printf("\n"); 
	head=reverse(head);
	output(head);
	freeloop(head);
	return 0;
}
