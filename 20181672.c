/*
정방행렬의 합과 곱 구하기

3x3 정방행열(Mat)을 입력 받아(9개의 정수)
 *입력 내용을 행렬형태로 출력
 *행렬의 합을 구하여 해렬형태로 출력
 *행렬의 곱을 구하여 행렬형태로 출력
 *모든 입출력은 main function에서 하고
 *행렬의 계산(합, 곱은 아래와 같은 function사용하여 구한다.

 Function indexAddMat()을 이용하여 합을 구함
 *Array indexing 방식으로 처리

 Function ptrProdMat()을 이용하여 곱을 구함
 *Pointer를 사용하여 Indexing
 */

#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3
#include <stdio.h>

void indexAddMat(int MatLeft[][3], int MatRight[][3], int MatResult[][3]);
void ptrProdMat(int (*MatLeft)[3], int (*MatRight)[3], int (*MatResult)[3]);
int main()
{
	int MatA[ROW][COL], MatB[ROW][COL], MatC[ROW][COL], MatD[ROW][COL], mrow, mcol;
	printf("첫번째 행렬을 입력하여 주세요\n일력 예:\n0 1 2\n3 4 5\n6 7 8\n>>\n");
	for (mrow = 0; mrow < ROW; mrow++)
	{
		for (mcol = 0; mcol < COL; mcol++)
		{
			scanf("%d", &MatA[mrow][mcol]);
		}
		while (getchar() != '\n');
	}
	printf("두번째 행렬을 입력하여 주세요\n일력 예:\n0 1 2\n3 4 5\n6 7 8\n>>\n");
	for (mrow = 0; mrow < ROW; mrow++)
	{
		for (mcol = 0; mcol < COL; mcol++)
		{
			scanf("%d", &MatB[mrow][mcol]);
		}
		while (getchar() != '\n');
	}
	printf("MatA\t\t\t\tMatB\n");
	for (mrow = 0; mrow < ROW; mrow++)
	{
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatA[mrow][mcol]);
		}
		printf("\t\t\t");
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatB[mrow][mcol]);
		}
		printf("\n");
	}
	indexAddMat(MatA, MatB, MatC);
	ptrProdMat(MatA, MatB, MatD);
	printf("MatA\t\t+\t\tMatB\t\t=\t\tMatC\n");
	for (mrow = 0; mrow < ROW; mrow++)
	{
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatA[mrow][mcol]);
		}
		printf("\t\t\t");
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatB[mrow][mcol]);
		}
		printf("\t\t\t");
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatC[mrow][mcol]);
		}
		printf("\n");
	}
	printf("MatA\t\t*\t\tMatB\t\t=\t\tMatD\n");
	for (mrow = 0; mrow < ROW; mrow++)
	{
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatA[mrow][mcol]);
		}
		printf("\t\t\t");
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatB[mrow][mcol]);
		}
		printf("\t\t\t");
		for (mcol = 0; mcol < COL; mcol++)
		{
			printf("%2d ", MatD[mrow][mcol]);
		}
		printf("\n");
	}
	
	return 0;
}

void indexAddMat(int MatLeft[][3], int MatRight[][3], int MatResult[][3])
{
	int MatRow, MatCol;
	for (MatRow = 0; MatRow < 3; MatRow++)
	{
		for (MatCol = 0; MatCol < 3; MatCol++)
		{
			MatResult[MatRow][MatCol] = MatLeft[MatRow][MatCol] + MatRight[MatRow][MatCol];
		}
	}
}

void ptrProdMat(int (*MatLeft)[3], int (*MatRight)[3], int (*MatResult)[3])
{
	int MatRow, MatCol, EleIter;
	for (MatRow = 0; MatRow < 3; MatRow++)
	{
		for (MatCol = 0; MatCol < 3; MatCol++)
		{
			*(*(MatResult + MatRow) + MatCol) = 0; //Eliminate junk data
			for (EleIter = 0; EleIter < 3; EleIter++)
			{
				*(*(MatResult + MatRow) + MatCol) += *(*(MatLeft + MatRow) + EleIter) * *(*(MatRight + EleIter) + MatCol);
			}
		}
	}
}
