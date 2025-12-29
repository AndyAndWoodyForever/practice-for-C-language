#include<stdio.h> 
#include<malloc.h>
#include<stdlib.h>

struct intNode{
	int value;
	struct intNode *next;
};

struct intNode *createchain(int n){
	struct intNode *head, *p, *tail;
	int i=0;
	head=tail=NULL;
	for(;i<n;i++){
		p=(struct intNode *)malloc(sizeof(struct intNode));
		p->value=i+1;
		p->next=NULL;
		if(head==NULL){
			head=tail=p;
		}else{
			tail->next=p;
			tail=p;
		}
	}
	tail->next=head; // 构成循环链表
	return head;
}

void freeloop(struct intNode *h){

	struct intNode *tail = h;
	while(tail->next != h){
		tail = tail->next;
	}
	tail->next = NULL; 

	struct intNode *p = h;
	struct intNode *temp;
	while(p != NULL){
		temp = p;
		p = p->next;
		free(temp);
	}
}

int main(){
	int people, calling;
	printf("请输入人数和报数阈值：");
	scanf("%d %d", &people, &calling);

	struct intNode *head = createchain(people);
	if(people == 1){
		printf("%d\n", head->value);
		free(head); // 直接释放单个节点
		head = NULL;
		return 0;
	}
	
	struct intNode *p = head; // 修正：p初始指向1号节点（报数起点）
	struct intNode *pre = NULL; // 前驱节点先置空
	struct intNode *take;
	int i=0;
	
	// 新增：找到1号节点（p）的前驱节点（尾节点），确保删除逻辑正常
	struct intNode *temp = head;
	while(temp->next != head){
		temp = temp->next;
	}
	pre = temp;

	
	if(calling == 1){

		for(; i<people; i++){
			printf("%d ", pre->next->value); 
			take = pre->next;
			pre->next = take->next;
			free(take);
		}
		printf("\n");
		return 0;
	}
	else {
		while(pre != p){
			for(i=0; i<calling-1; i++){
				pre = p;
				p = p->next;
			}
			printf("%d ", p->value); 
			take = p;
			p = p->next;
			pre->next = p;
			free(take);
		}
		printf("%d\n", p->value);
		free(p);
		head = NULL;
	}
	
	return 0;
}
