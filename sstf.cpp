#include<stdio.h>
#include<math.h>
int main()
{
	int RQ[100],i,n,TotalHeadMoment=0,initial,count=0;
	printf("Enter the number of requests:");
	scanf("%d",&n);
	printf("Enter the Requests Sequence:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&RQ[i]);
	}
	printf("Enter initial head position:");
	scanf("%d",&initial);
	
	while(count!=n)
	{
		int min=1000,d,index;
		for(i=0;i<n;i++)
		{
			d=abs(RQ[i]-initial);
			if(min>d)
			{
				min=d;
				index=i;
			}
		}
		TotalHeadMoment+=min;
		initial=RQ[index];
		RQ[index]=1000;
		count++;
	}
	
	printf("Total Seek Time: %d", TotalHeadMoment);
	return 0;
}
