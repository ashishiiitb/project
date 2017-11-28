#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Adjlist
{
	int v;
	struct adjlist* next;
};

struct Arraylist
{
	struct adjlist *head;
};

struct Graph
{
	int ver;
	struct Arraylist *array;
};

struct Graph *creategraph(int v){
	struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
	graph->ver=v;
	graph->array=(struct Arraylist *)malloc(sizeof(struct Arraylist)*v);
	for(int i=0;i<v;i++){
		graph->array[i].head=NULL;
	}
	return graph;
}

void addedge(struct Graph *graph,int src,int des){
	struct Adjlist *node=(struct Adjlist *)malloc(sizeof(struct Adjlist));
	node->v=des;
	node->next=graph->array[src].head;
	graph->array[src].head=node;
	//below code is valid for only undirected grpah
	node=(struct Adjlist*)malloc(sizeof(struct Adjlist));
	node->v=src;
	node->next=graph->array[des].head;
	graph->array[des].head=node;
}

void printgraph(struct Graph *graph,int v){
	for(int i=0;i<v;i++){
		printf("Adj vertex of node %d : ",i);
		struct Adjlist *node=graph->array[i].head;
		while(node!=NULL){
			printf("-> %d",node->v);
			node=node->next;
		}
		printf("\n");
	}
}

int queue[100],front=-1,rear=-1;

void enqueue(int x){
	if(front==-1 && rear==-1){
		front++;
		rear++;
		queue[front]=x;
	}else{
		front++;
		queue[front]=x;
	}
}

int dequeue(){
	int temp=queue[rear];
	//printf("%d\n",temp );
	rear++;
	return temp;
}

void BFS(struct Graph* graph,int src){
	int v=graph->ver;
	int visit[v];
	for (int i = 0; i < v; ++i)
	{
		visit[i]=0;
	}
	enqueue(src);
	visit[src]=1;
	printf("breadth first traversal:\n");
	while(rear < v){
		//printf("Hello\n");
		int t=dequeue();
		printf("%d ",t);
		//printf("\nhello");
		struct Adjlist* temp=graph->array[t].head;
		while(temp!=NULL){
			if(visit[temp->v]!=1){
				enqueue(temp->v);
				visit[temp->v]=1;
			}
			temp=temp->next;
		}
	}

}

int main(){
	int v=5;
	struct Graph *graph=creategraph(v);
	addedge(graph,0,1);
	addedge(graph,1,2);
	addedge(graph,4,3);
	addedge(graph,2,3);
	addedge(graph,0,4);
	addedge(graph,3,1);
	printgraph(graph,v);
	BFS(graph,0);
	
}
