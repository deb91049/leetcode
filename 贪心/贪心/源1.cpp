#include<stdio.h>
#define MAX 100

struct bag
{
	int value;
	int weight;
	double vw;
}a[MAX];

int main() {
	int capacity,n;
	printf("请输入背包容量和物品个数\n");
	scanf_s("%d%d", &capacity, &n);

	printf("请输入物品价值和重量\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d", &a[i].value, &a[i].weight);
		a[i].vw = 1.0 * a[i].value / a[i].weight;
	}

	//根据单位价值a[i].vw排序
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n - i; j++) {
			int tempV, tempW, tempVw;
			if (a[j].vw < a[j + 1].vw) {
				tempVw = a[j].vw;
				a[j].vw = a[j + 1].vw;
				a[j + 1].vw = tempVw;

				tempV = a[j].value;
				a[j].value = a[j + 1].value;
				a[j + 1].value = tempV;

				tempW = a[j].weight;
				a[j].weight = a[j + 1].weight;
				a[j + 1].weight = tempW;

			}
		}
	}

	//贪心算法
	int cu = capacity;
	double sum = 0;
	int i = 0;
	double rate = 0;
	for (i = 0; i < n; i++) {
		if (cu < a[i].weight) {
			break;
		}
		else {
			sum += a[i].value;
			cu -= a[i].weight;
			printf("价值为%d的物品,单位价值为%f,拿了100%%\n", a[i].value,a[i].vw);
		}
	}
	if (i < n&& cu!=0) {
		rate = 1.0*cu / a[i].weight;
		sum += a[i].value * rate;
		printf("价值为%d的物品,单位价值为%f,拿了%f\n", a[i].value, a[i].vw, rate);
	}
	printf("背包里的物品的价值总和最大为 %f\n", sum);	
	return 0;


}