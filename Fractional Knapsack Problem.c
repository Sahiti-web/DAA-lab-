# include<stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity) {
	float x[20],totalProfit=0.0,remainingCapacity;
	int i,j;
	remainingCapacity=capacity;
	for(i=0;i<n;i++)
		x[i]=0.0;
	for(i=0;i<n;i++){
		if (weight[i]>remainingCapacity)
			break;
		else{
			x[i]=1.0;
			totalProfit+=profit[i];
			remainingCapacity-=weight[i];
		}
	}
	if(i<n){
		x[i]=remainingCapacity/weight[i];
		totalProfit+=x[i]*profit[i];
	}
	printf("Maximum profit is:- %f\n",totalProfit);
}

int main() {
	float weight[20], profit[20], capacity;
	int num, i, j;
	float ratio[20], temp;
	printf("Enter the no. of objects: ");
	scanf("%d", &num);
	printf("Enter the weights and profits of each object:\n");
	for (i = 0; i < num; i++) {
		scanf("%f %f", &weight[i], &profit[i]);
	}
	printf("Enter the capacity of knapsack:");
	scanf("%f", &capacity);
	for (i = 0; i < num; i++) {
}
