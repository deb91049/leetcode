#include<stdio.h>
#include<algorithm>

/*����ṹ����Ʒ*/
struct node
{
    int v, w;         // vΪ��ֵ  wΪ��Ʒ����
    double x = 1.0 * v / w;   //x����λ��ֵ
}a[101];


int main()
{
    int i, j, sum, s, m;
    sum = 0;
    printf("������Ʒ�ĸ����ͱ�������\n");
    scanf_s("%d%d", &s, &m);   //sΪ��Ʒ������m��Ϊ��������
    printf("������Ʒ�ļ�ֵ����Ʒ����\n");
    for (i = 0; i < s; i++)
        scanf_s("%d%d", &a[i].v, &a[i].w);


    int tmp = 0;
    for (int i = 0; i < s; i++)  //�Ӱ���λ��ֵ �Ӵ�С����
    {
        for (int j = 0; j < s - i; j++)
        {
            if (a[j].x < a[j + 1].x)
            {
                tmp = a[j + 1].x;
                a[j + 1].x = a[j].x;
                a[j].x = tmp;
            }
        }
    }
    /*̰���㷨����*/
    for (i = 0; i < s; i++)
    {
        if (m < a[i].w)
        {
            sum = sum + a[i].x * m;//�����ɲ�
            m = 0;
            break;
        }
        else
        {
            sum = sum + a[i].v;
            m = m - a[i].w;
        }
    }
    printf("���������Ʒ�ļ�ֵ�ܺ����Ϊ %d\n", sum);
    return 0;
}
