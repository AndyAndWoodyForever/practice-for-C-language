#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

struct intNode{
	int value;
	struct intNode *next;
};

struct intNode * createChain()
{
	int k;
	struct intNode * head,* tail, *p;
	tail=head=(struct intNode *)malloc(sizeof(struct intNode));
	head->value=-1;//¸¨Öú±íÔª 
	head->next=NULL;
	do{
		scanf("%d",&k);
		if(k==-1)break;
		p=(struct intNode *)malloc(sizeof(struct intNode));
		p->value=k;
		p->next=NULL;
		tail->next=p;
		tail=p;
	}while(1);
	return head;
}
void outputChain(struct intNode *head){
	struct intNode *p=head;
	while(p!=NULL){
		printf("%d",p->value);
		p=p->next;
	}
    
}
void freeChain(struct intNode *head){
	struct intNode *p;
	for(p=head;p;p=head){
		head=head->next;
		free(p);
	}
}

