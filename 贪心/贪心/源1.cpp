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
	printf("�����뱳����������Ʒ����\n");
	scanf_s("%d%d", &capacity, &n);

	printf("��������Ʒ��ֵ������\n");
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d", &a[i].value, &a[i].weight);
		a[i].vw = 1.0 * a[i].value / a[i].weight;
	}

	//���ݵ�λ��ֵa[i].vw����
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

	//̰���㷨
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
			printf("��ֵΪ%d����Ʒ,��λ��ֵΪ%f,����100%%\n", a[i].value,a[i].vw);
		}
	}
	if (i < n&& cu!=0) {
		rate = 1.0*cu / a[i].weight;
		sum += a[i].value * rate;
		printf("��ֵΪ%d����Ʒ,��λ��ֵΪ%f,����%f\n", a[i].value, a[i].vw, rate);
	}
	printf("���������Ʒ�ļ�ֵ�ܺ����Ϊ %f\n", sum);	
	return 0;


}