#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ------------------- Common Function -------------------
void printArray(int arr[], int size) {
    for (int k = 0; k < size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

// ------------------- Insertion Sort -------------------
void insertionSort() {
    int i, j, temp, len;
    printf("Enter the length of array: ");
    if (scanf("%d", &len) != 1 || len <= 0) {
        printf("Invalid length entered.\n");
        return;
    }

    int array[len];
    printf("Enter %d numbers\n", len);

    for (i = 0; i < len; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Error reading input.\n");
            return;
        }
    }

    printf("\n--- Starting Insertion Sort ---\n");
    printf("Initial Array: ");
    printArray(array, len);

    for (i = 1; i < len; i++) { 
        j = i;
        printf("\nPass %d: Considering element %d (at index %d)\n", i, array[i], i);
        
        while (j > 0 && array[j - 1] > array[j]) {
            
            temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;

            printf("  Swapped %d and %d. Array state: ", array[j], array[j-1]);
            printArray(array, len);

            j--;
        }
        
    }

    printf("\n--- Sorting Complete ---\n");
    printf("Sorted Array: ");
    printArray(array, len);
}

// ------------------- Merge Sort -------------------
void printArrayMerge(int *arr, int size)
{
	for (int i=0; i<size; i++)
		printf("%d ",arr[i]);
	puts("");
}

void Merge(int arr[], int p, int q, int r, int size)
{
	int n1,n2,i,j,k;
	n1 = q - p + 1;  //Calculating array size for left array 
	n2 = r - q;      //Calculating array size for right array 
	
	int *LeftArray = malloc((n1 + 1) * sizeof(int));  //allocation of dynamic memory
	int *RightArray = malloc((n2 + 1) * sizeof(int)); 
	
	if (LeftArray == NULL || RightArray == NULL) 
	{
    printf("Memory allocation failed!\n");  //Error handling
    exit(1);
	}
	
	for (i=0; i<n1; i++)
	LeftArray[i] = arr[p + i ];  //Filling the sub array with values from the original array
	
	for (j=0; j<n2; j++)
	RightArray[j] = arr[q + 1 + j ]; 
	
	LeftArray[n1]= INT_MAX;  //Trying to put infinty in last cell of the sub arrays 
	RightArray[n2]= INT_MAX; //but 1/0 will give error so we just store the max value
	
	i=0; j=0;    			//Re-initializing the pointers of left and right sub arrays
								
	for (k=p; k<=r; k++)     
	{
		if (LeftArray[i] <= RightArray[j])
		{
			arr[k] = LeftArray[i];
			i++;					  	//Comparing both arrays with each other
		}								//and storing them in the original array in the right order
		else
		{
			arr[k] = RightArray[j];
			j++;
		}
	}
	
	printf("Merged [%d, %d]: ", p, r); //Printing for Visualization
    printArrayMerge(arr, size);				//not a neccessary step
	printf("\n");
	
    free(LeftArray);
    free(RightArray); // free the memory since it was manually allocated
}

void divideArray(int arr[], int p, int r, int size)
{
    if (p < r)
    {
        int q = (int)((p+r)/2);  //Finding mid-point

        // Printing the current segment before dividing
        printf("Dividing Array [%d..%d]: ", p, r); 		//For Visualization only
        for (int i = p; i <= r; i++)					//Not neccessary steps
            printf("%d ", arr[i]);
        printf("\n");

        // Recursion calls
        divideArray(arr, p, q, size);
        divideArray(arr, q + 1, r, size);

        // Printing left and right subarrays before merging
        printf("\n");
		printf("Left Array [%d..%d]: ", p, q); 		//For Visualization only
        for (int i = p; i <= q; i++)				//Not neccessary steps
            printf("%d ", arr[i]);
        printf("\n");

        printf("Right Array [%d..%d]: ", q + 1, r); //For Visualization only
        for (int i = q + 1; i <= r; i++)			//Not neccessary steps
            printf("%d ", arr[i]);
        printf("\n");

        // Merging the subarrays
        Merge(arr, p, q, r, size);
    }
}

void mergeSort() {
    int len;
	printf("Enter the length of array: ");
	scanf("%d",&len);
	
	int arr[len];
	printf("Enter %d numbers: \n",len);
	for (int i=0; i<len; i++)
	scanf("%d",&arr[i]);
	
    divideArray(arr, 0, len - 1,len);

    printf("\n\nSorted array: ");
    for (int i = 0; i < len; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ------------------- Bubble Sort -------------------
void printArrayBubble(int *array,int n)
{
	printf("\n[");
		for (int k=0;k<n;k++){
			printf (" %d ",array[k]);
		}
		printf("]\n");
}

void bubbleSort() {
    int len,opt,i;

    printf("Enter number of element : ");
    scanf("%d",&len);

    int arr[len];                     

    for (int i=0;i<len;i++){
        printf("\nEnter %d element : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nSelect weather you want to arrange the array in Accending or Decending order\n1: Ascending\n2: Descending\n\n");
    scanf("%d",&opt);

    printf("orignal array\n[");
    for (int i=0;i<len;i++){
        printf(" %d ",arr[i]);
    }
    printf("]\n");

    switch(opt){
        case 1:
            for(i=0;i<len-1;i++){
                int temp;
                printf("\n%d pass \n[",i+1);
                for (int k=0;k<len;k++){
                    printf (" %d ",arr[k]);
                }
                printf("]\n");
                for(int j=0;j<len-1-i;j++){
                    if (arr[j]>arr[j+1]){
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                    printArrayBubble(arr,len);
                }
            }
            break;
   
        case 2:
            for(i=0;i<len-1;i++){
                int temp;
                printf("\n%d swap \n[",i+1);
                for (int k=0;k<len;k++){
                    printf (" %d ",arr[k]);
                }
                printf("]\n");
                for(int j=0;j<len-1-i;j++){
                    if (arr[j]<arr[j+1]){
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                    printArrayBubble(arr,len);
                }
            }
            break;
  
        default:
            printf("Invalid option");
    }
}

// ------------------- Unified Main -------------------
int main() {
    int choice;
    printf("Select which sorting algorithm you would like to use:\n");
    printf("1. Insertion Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Bubble Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            insertionSort();
            break;
        case 2:
            mergeSort();
            break;
        case 3:
            bubbleSort();
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}
