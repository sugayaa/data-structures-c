#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
#define FULL_QUEUE -2
#define EMPTY_QUEUE -3
#define item_type int

typedef struct queue{
	item_type body[MAX];
	int start, end;
}queue;

queue queue_1 = {
	.start = -1,
	.end = -1
};

void initQueue(queue* q){
	q->start = -1;
	q->end = -1;
}

int emptyQueue(queue* q){
	return q->end == -1 && q->start == -1;
}

int fullQueue(queue *q){
	return q->end == q->start - 1;
}

void push(queue* q, item_type x){
	if(fullQueue(q))
		printf("Full Queue!!\n");
		return;
	if(emptyQueue(q))
		q->start += 1;
	q->end = (q->end + 1) % MAX;
	q->body[q->end] = x;
}

item_type front(queue* q){
	return q->body[q->start];
}

item_type pop(queue* q){
	if(emptyQueue(q))
		return EMPTY_QUEUE;

	item_type return_ = q->body[q->start];
	if(q->start == q->end){
		q->start = -1;
		q->end = -1;
	}else{
		q->start += 1;
	}
	return return_;
}

void clearQueue(queue* q){
	q->start = -1;
	q->end = -1;
}

void printQueue(queue* q){
	int i;
	if(emptyQueue(q)){
		printf("Empty Queue!");
	}else{
		for(i = q->start; i != q->end + 1; (i += 1) % MAX)
			printf("%d ", q->body[i]);
		printf("\n");
	}
}

int main(){
	push(&queue_1, 1);
	push(&queue_1, 2);
	//imprimeFila(&queue_1);
	printf("%d\n", pop(&queue_1));
	//imprimeFila(&queue_1);
	printf("%d\n", pop(&queue_1));
	//imprimeFila(&queue_1);

}
