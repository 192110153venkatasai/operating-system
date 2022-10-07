#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int p[a];
    int i,QT,count=0,temp,sq=0,BT[a],WT[a],TAT[a],rem_BT[a];
    float AWT=0,ATAT=0;
    printf("process:");
    for(i=0;i<a;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("burst time:");
    for(i=0;i<a;i++)
    {
        scanf("%d",&BT[i]);
        rem_BT[i]=BT[i];
    }
    printf("enter quantum time");
    scanf("%d",&QT);
    while(1)
    {
        for(i=0,count=0;i<a;i++)
        {
            temp=QT;
            if(rem_BT[i]==0)
            {
                count++;
                continue;
            }
            if(rem_BT[i]>QT)
                rem_BT[i]=rem_BT[i]-QT;            
            else
                if(rem_BT[i]>=0)
                {
                    temp=rem_BT[i];
                    rem_BT[i]=0;
                }
                sq=sq+temp;
                TAT[i]=sq;
        }
        if(a==count)
        {
            break;
        }
    }
    printf("\nprocess\tburst time\tturnaround time\twaiting time\n");
    for(i=0;i<a;i++)
    {
        WT[i]=TAT[i]-BT[i];
        AWT=AWT+WT[i];
        ATAT=ATAT+TAT[i];
        printf("\n%d\t\t%d\t\t\t\t%d\t\t\t\t%d",i+1,BT[i],TAT[i],WT[i]);
    }
    AWT=AWT/a;
    ATAT=ATAT/a;
    printf("\naverage waiting time=%f\n",AWT);
    printf("average turnaround time=%f\n",ATAT);
}
