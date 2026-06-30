#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#define MAXSIZE 100
#define INF 0x3f3f3f3f
typedef struct {
	char vertex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int vertexes;
	int visited[MAXSIZE];
}Matrixgraph;

void makegraph(Matrixgraph* M);
void prime(Matrixgraph* M);
void ShowMenu();

void makegraph(Matrixgraph* M) {
	M->vertex[0] = 'A';
	M->vertex[1] = 'B';
	M->vertex[2] = 'C';
	M->vertex[3] = 'D';
	M->vertex[4] = 'E';
	M->vertex[5] = 'F';
	M->vertex[6] = 'G';
	M->vertex[7] = 'H';
	M->vertex[8] = 'I';
	M->vertexes = 9;
	for (int i = 0; i < M->vertexes; i++) {
		for (int j = 0; j < M->vertexes; j++) {
			if (i == j) {
				M->arc[i][j] = 0;
			}
			else {
				M->arc[i][j] = INF;
			}

		}
	}
		//A
		M->arc[0][1] = 10;
		M->arc[0][5] = 11;
		//B
		M->arc[1][2] = 18;
		M->arc[1][8] = 12;
		M->arc[1][6] = 16;
		//C
		M->arc[2][3] = 22;
		M->arc[2][8] = 8;
		//D
		M->arc[3][4] = 20;
		M->arc[3][6] = 24;
		M->arc[3][7] = 16;
		M->arc[3][8] = 21;
		//E
		M->arc[4][5] = 26;
		M->arc[4][7] = 7;
		//F
		M->arc[5][6] = 17;
		//G
		M->arc[6][7] = 19;
		for (int i = 0; i < M->vertexes; i++) {
			for (int j = 0; j < M->vertexes; j++) {
				M->arc[j][i] = M->arc[i][j];
			}
		}
	
}
void Matrix(Matrixgraph* M) {
	for (int i = 0; i < M->vertexes; i++) {
		for (int j = 0; j < M->vertexes; j++) {
			if (M->arc[i][j] == INF) {
				printf("INF\t");
			}
			else {
				printf("%d\t", M->arc[i][j]);
			}
		}
		printf("\n");
	}
}
void AdjacencyList(Matrixgraph* M) {
	for (int i = 0; i < M->vertexes; i++) {
		printf("%c: ", M->vertex[i]);
		for (int j = 0; j < M->vertexes; j++) {
			if (M->arc[i][j] != INF && M->arc[i][j] != 0) {
				printf("->%c(%d) ", M->vertex[j], M->arc[i][j]);
			}
		}
		printf("\n");
	}
}
void DepthFirstSearch(Matrixgraph* M, int n, int* visited) {
	visited[n] = 1;
	printf("%c\t", M->vertex[n]);
	for (int j = 0; j < M->vertexes; j++) {
		if(visited[j] == 0 && M->arc[n][j] != INF && M->arc[n][j] != 0) {
			DepthFirstSearch(M, j, visited);
		}
	}
}
void BroadFirstSearch(Matrixgraph* M ) {
	int visited[MAXSIZE];
	int n;
	scanf("%d", &n);
	for(int i=0;i<M->vertexes;i++){
		visited[i]=0;
	}
	int queue[MAXSIZE];
	int front = 0;
	int rear = 0;
	int i;
	visited[n] = 1;
	printf("%c\t", M->vertex[n]);
	queue[rear] = n;
	rear++;
	while (rear != front) {
		i = queue[front++];
		for (int j = 0; j < M->vertexes; j++) {
			if (visited[j] == 0 && M->arc[i][j] != INF && M->arc[i][j] != 0) {
				visited[j] = 1;
				printf("%c\t", M->vertex[j]);
				queue[rear] = j;
				rear++;
			}
		}
	}
}
void prime(Matrixgraph* M) {
	char start;
	printf("请输入起始顶点: ");
	scanf(" %c", &start);
	int weight[MAXSIZE];
	int vex_index[MAXSIZE];
	int i, j, k;
	j = 0;
	int min = INF;
	for (i = 0; i < M->vertexes; i++) {
		if (M->vertex[i] == start) {
			for (j = 0; j < M->vertexes; j++) {
				weight[j] = M->arc[i][j];
				vex_index[j] = i;
			}
			break;
		}
	}
	for (i = 1; i < M->vertexes; i++) {
		min = INF;
		j = 0;
		k = 0;
		while (j < M->vertexes) {
			if (weight[j] != 0 && weight[j] < min) {
				min = weight[j];
				k = j;
			}
			j++;
		}
		printf("%c-%c\t", M->vertex[vex_index[k]], M->vertex[k]);
		weight[k] = 0;
		for (j = 0; j < M->vertexes; j++) {
			if (weight[j] != 0 && M->arc[k][j] < weight[j]) {
				weight[j] = M->arc[k][j];
				vex_index[j] = k;
			}
		}
	}
}
void ShowMenu() {
	system("cls");
	printf("===================================\n");
	printf("         1. 输出邻接矩阵\n");
	printf("         2. 输出邻接表\n");
	printf("         3. 深度优先\n");
	printf("         4. 广度优先\n");
	printf("         5. Prime算法\n");
	printf("===================================\n");
}


int main() {
	int choice;
	Matrixgraph M;
	makegraph(&M);
	while (1) {
		ShowMenu();
		printf("请输入您的选择 (0-5): ");
		if (scanf("%d", &choice) != 1) {
			printf("\n 输入非法！请输入数字。\n");
			system("pause");
			continue;
		}
		switch (choice) {
		case 1: Matrix(&M); system("pause");
		break;
		case 2: AdjacencyList(&M); system("pause");
		break;
		case 3:int visited[MAXSIZE];
			int n;
			scanf("%d", &n);
			for (int i = 0; i < M.vertexes; i++) {
				visited[i] = 0;
			}
			DepthFirstSearch(&M, n, visited); system("pause");
		break;
		case 4: BroadFirstSearch(&M); system("pause");
		break;
		case 5: prime(&M); system("pause");
		break;
		case 0: printf("退出程序。\n"); return 0;
		default:
			printf("\n 输入非法！请输入0-5之间的数字。\n");
			system("pause");
			break;
		}
	}
}