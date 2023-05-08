#include<stdio.h>

int main(){
    int at[10] , bt[10] , sum_tat = 0 , sum_bt = 0 , sum_wt = 0 , time , n , smallest;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter at of P%d: " , i+1);
        scanf("%d", &at[i]);

        printf("\nEnter bt of P%d: " , i+1);
        scanf("%d", &bt[i]);

        sum_bt += bt[i];
    }

    bt[9] = 999;

    for (int time = 0 ; time <sum_bt; )
    {
        smallest = 9;
        for (int i = 0; i < n; i++)
        {
            if(at[i] <= time && bt[i] > 0 && bt[i] < bt[smallest])
                smallest = i;
        }

        printf("\nProcesses \t\t wt \t\t tat \t\t ct\n");
        printf("%d\t\t %d\t\t %d\t\t%d\n" , smallest+1 , time-at[smallest] , time+bt[smallest] - at[smallest] , time+bt[smallest]);

        sum_tat += time + bt[smallest] - at[smallest];
        sum_wt += time - at[smallest];
        time += bt[smallest];
        bt[smallest] = 0;
    }
    printf("\nAvg TAT = %f\n", sum_tat * 1.0 / n);
    printf("\nAvg WT = %f\n", sum_wt * 1.0 / n);
    
    return 0;
}