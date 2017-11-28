#include<stdio.h>
#include<stdlib.h>

struct Adjlist
{
	int v;
	int weight;
	struct adjlist* next;
};

struct Arraylist
{
	struct adjlist *head;
};

struct Graph
{
	int ver;
	struct Arraylist* array;
};

struct Graph* creategraph(int v){
	struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->ver=v;
	graph->array=(struct Arraylist*)malloc(sizeof(struct Arraylist)*v);
	for(int i=0;i<v;i++){
		graph->array[i].head=NULL;
	}
	return graph;
}

void addedge(struct Graph* graph,int src,int des, int weight){
	struct Adjlist* node=(struct Adjlist*)malloc(sizeof(struct Adjlist));
	node->v=des;
	node->weight=weight;
	node->next=graph->array[src].head;
	graph->array[src].head=node;
	//below code is valid for only undirected grpah
	/*node=(struct Adjlist*)malloc(sizeof(struct Adjlist));
	node->v=src;
	node->next=graph->array[des].head;
	graph->array[des].head=node;*/
}

void printgraph(struct Graph* graph,int v){
	for(int i=0;i<v;i++){
		printf("Adj vertex of node %d : ",i);
		struct Adjlist* node=graph->array[i].head;
		while(node!=NULL){
			printf("-> %d %d",node->v,node->weight);
			node=node->next;
		}
		printf("\n");
	}
}

int min_weight(struct Graph *graph,int weight[],int parent[],int visit[],int src){
	int min= INT_MAX;
	int minindex;
	//struct Adjlist *temp;
	//temp=graph->array[vertex].head;
	minindex=-1;
	while(temp){
		if(visit[temp->v]==0){
			if(weight[temp->v]>=temp->weight){
				weight[temp->v]=temp->weight;
				parent[temp->v]=vertex;
				if(min>=temp->weight){
					min=temp->weight;
					minindex=temp->v;
				}
			}else{
				if(min>weight[temp->val]){
					min=value[temp->val];
					minindex=temp->val;
				}
			}

		}
		temp=temp->next;
	}
	return minindex;
}

void Dijkshra(struct Graph *graph,int src){
	int v=graph->ver;
	int weight[v];
	int visit[v];
	int parent[v];
	weight[src]=0;
	parent[src]=-1;
	for(int i=0;i<v;i++){
		visit[i]=0;
		if(src!=i){
			weight[i]=99999;
			parent[i]=99999;
		}
	}

	for(int i=0;i<v;i++){

		index2=min_weight(graph,weight,parent,visit,src);
		visit[index2]=1;
	}
	for(int i=0;i<v;i++){
		printf("%d %d %d \n",weight[i],visit[i],parent[i]);
	}
}

int main(){
	int v=9;
	struct Graph *graph=creategraph(v);
	addedge(graph,0,1,4);
	addedge(graph,0,7,8);
	addedge(graph,1,2,8);
	addedge(graph,1,7,11);
	addedge(graph,2,3,7);
	addedge(graph,2,8,2);
	addedge(graph,2,5,4);
	addedge(graph,3,4,9);
	addedge(graph,3,5,14);
	addedge(graph,4,5,10);
	addedge(graph,5,6,2);
	addedge(graph,6,7,1);
	addedge(graph,6,8,6);
	addedge(graph,7,8,7);
	printgraph(graph,v);
	Dijkshra(graph,0);
	
}