#include<stdio.h>
#include<algorithm>

/*定义结构体物品*/
struct node
{
    int v, w;         // v为价值  w为物品重量
    double x = 1.0 * v / w;   //x代表单位价值
}a[101];


int main()
{
    int i, j, sum, s, m;
    sum = 0;
    printf("输入物品的个数和背包容量\n");
    scanf_s("%d%d", &s, &m);   //s为物品个数，m，为背包容量
    printf("输入物品的价值和物品重量\n");
    for (i = 0; i < s; i++)
        scanf_s("%d%d", &a[i].v, &a[i].w);


    int tmp = 0;
    for (int i = 0; i < s; i++)  //从按单位价值 从大到小排序
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
    /*贪心算法核心*/
    for (i = 0; i < s; i++)
    {
        if (m < a[i].w)
        {
            sum = sum + a[i].x * m;//背包可拆
            m = 0;
            break;
        }
        else
        {
            sum = sum + a[i].v;
            m = m - a[i].w;
        }
    }
    printf("背包里的物品的价值总和最大为 %d\n", sum);
    return 0;
}
