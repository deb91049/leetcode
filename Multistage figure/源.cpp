// 动态规划  
// 多段图寻找结点间最短路径的实现


#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
typedef int VertexType;//��������
typedef int EdgeType;//Ȩֵ����

//�߱����
typedef struct EdgeNode {
	
	int adjvex;  //�ڽӵ㣬�洢�ö����Ӧ�±�
	int weight;  //Ȩֵ
	struct EdgeNode* next;  //ָ����һ�ڽӵ�ָ��
}EdgeNode;

//��������
typedef struct VertexNode {  
	VertexType data;
	EdgeNode* firstedge; //�߱�ͷָ��
}VertexNode,AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes;
}GraphAdjList;

void CreateALGraph(GraphAdjList* G, int n);
void PrintGraph(GraphAdjList* G);
void Search(GraphAdjList* G, int n, int k);


int main() {
	GraphAdjList* G= (GraphAdjList*)malloc(sizeof(GraphAdjList));
	printf("�����붥����,������\n");
	int n, k;
	scanf_s("%d %d", &n,&k);
	CreateALGraph(G,n);
	//PrintGraph(G);
	Search(G,n,k);
	return 0;
}

/* ����ͼ���ڽӱ��ṹ*/
void CreateALGraph(GraphAdjList* G,int n) {
	EdgeNode* e;
	G->numVertexes = n;
	/* ��ʼ��������Ϣ*/
	for (int i = 0; i < G->numVertexes; i++) {
		G->adjList[i].data = i +1;
		G->adjList[i].firstedge = NULL;
	}
	/*�����߱�*/
	printf("���������Ϣ������a������b��Ȩֵ����0������\n");
	while (true) {
		int a, b, weight;
		scanf_s("%d%d%d", &a, &b, &weight);
		if (a == 0)
			break;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = b;
		e->weight = weight;
		e->next = G->adjList[a-1].firstedge;
		G->adjList[a-1].firstedge = e;		
	}
}


void PrintGraph(GraphAdjList* G) {
	
	EdgeNode* temp = (EdgeNode*)malloc(sizeof(EdgeNode));
	printf("���������Ϊ\n");
	for (int i = 0; i < G->numVertexes; i++) {
		int weight;
		while (G->adjList[i].firstedge != NULL) {
			weight = G->adjList[i].firstedge->weight;			
			printf("%d-%d:\t%d\t\t", G->adjList[i].data,G->adjList[i].firstedge->adjvex,weight);
			G->adjList[i].firstedge = G->adjList[i].firstedge->next;
		}
		printf("\n");
	}
}


void Search(GraphAdjList* G, int n, int k) {

	int cost[MAXVEX] = {0};
	int pre[MAXVEX] = { 0 };
	int route[MAXVEX] = { 0 };
	int i = 0;
	int j = 0;

	printf("�������%d\n", n);

	//�������
	for (int i = n - 1; i >= 0; i--) {
		int min = 65535;
		//�������ı߱�
		while (G->adjList[i].firstedge!=NULL ) {
			//min{weight+cost[i]}
			if ((G->adjList[i].firstedge->weight+cost[(G->adjList[i].firstedge->adjvex)-1])<=min ){
				min = G->adjList[i].firstedge->weight + cost[G->adjList[i].firstedge->adjvex - 1];
				cost[i] = min;
				pre[i] = G->adjList[i].firstedge->adjvex;
			}
			G->adjList[i].firstedge = G->adjList[i].firstedge->next;
		}
		
	}

	
	//��¼·��
	route[0] = 1;
	route[k-1] = n;
	for (int i = 1; i < k-1; i++) {		
		route[i] = pre[route[i - 1]-1];
	}

	printf("��С�ɱ���Ϊ��%d\n",cost[0]);
	printf("��С�ɱ�·��Ϊ��");

	for (int i = 0; i < k; i++) {
		if (i != (k - 1)) {
			printf("%d->", route[i]);
		}
		else {
			printf("%d\n", route[i]);
		}		
	}

}
/*
1 2 9
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11
5 8 8
6 9 6
6 10 5
7 9 4
7 10 3
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5
0 0 0
*/