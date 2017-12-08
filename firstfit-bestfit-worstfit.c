#include <stdio.h>
#include <malloc.h>

int main()
{
    int *p, flag[100], mem1[100], mem2[100], i, j, n, m, process[10], ch, alloc[100], temp;
    printf("Enter the number of process\n");
    scanf("%d", &n);
    printf("Enter each process block size\n");
    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);
    printf("Enter the number of memory blocks\n");
    scanf("%d", &m);
    p = (int *)malloc(m * sizeof(int));
    printf("Enter each memory block size\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", (p + i));
        mem1[i] = *(p + i);
        mem2[i] = *(p + i);
    }
    while (1)
    {
        printf("Enter choice: 1.First Fit\t 2.Best Fit\t 3.Worst Fit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        /* First Fit */
        case 1:
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if (process[i] <= (*(p + j)))
                    {
                        alloc[i] = *(p + j);
                        *(p + j) = *(p + j) - process[i];
                        flag[i] = 0;
                        break;
                    }
                }
                if (j == m)
                {
                    flag[i] = 1;
                }
            }
            for (i = 0; i < n; i++)
            {
                if (flag[i] == 0)
                    printf("p %d of %d allocated to %d\n", i + 1, process[i], alloc[i]);
                else
                    printf("p %d of %d must wait\n", i + 1, process[i]);
            }
            break;
        /* Best Fit */
        case 2:
            for (i = 0; i < m; i++)
                for (j = i + 1; j < m; j++)
                {
                    if (mem1[i] > mem1[j])
                    {
                        temp = mem1[i];
                        mem1[i] = mem1[j];
                        mem1[j] = temp;
                    }
                }
            printf("After sorting memory blocks are\n");
            for (i = 0; i < m; i++)
                printf("%d\n", mem1[i]);
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    if (process[i] <= mem1[j])
                    {
                        alloc[i] = mem1[j];
                        mem1[j] = 0;
                        flag[i] = 0;
                        break;
                    }
                }
                if (j == m)
                {
                    flag[i] = 1;
                }
            }
            for (i = 0; i < n; i++)
            {
                if (flag[i] == 0)
                    printf("p %d of %d allocated to %d\n", i + 1, process[i], alloc[i]);
                else
                    printf("p %d of %d must wait\n", i + 1, process[i]);
            }
            break;
        /* Worst Fit */
        case 3:
            for(i=0;i<m;i++)
                for(j=i+1;j<m;j++)
                    if(mem2[i]<mem2[j]){
                        temp=mem2[i];
                        mem2[i]=mem2[j];
                        mem2[j]=temp;
                    }
            printf("After sorting memory blocks are\n");
            for(i=0;i<m;i++)
                    printf("%d\n",mem2[i]);
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    if(process[i]<=mem2[j]){
                        alloc[i]=mem2[j];
                        mem2[j]=mem2[j]-process[i];
                        flag[i]=0;
                        break;
                    }
                }
                if(j==m)
                {
                    flag[i]=1;
                }
            }
            for(i=0;i<n;i++){
                if(flag[i]==0)
                    printf("p %d of %d allocated to %d",i+1,process[i],alloc[i]);
                else
                    printf("p %d of %d must wait\n",i+1,process[i]);
            }
            break;
        default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}