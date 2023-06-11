/*  Kyutza Lopez
    COP 3223C
    PROGRAM STATS
    3/14/23     */

#include <stdio.h>
#include <math.h>
void readGrades(double grades[100], int *n);
int maximum(double grades[], int n);
int minimum(double grades[], int n);
void deleteElement(double grades[], int *n, int loc);
double mean(double grades[], int n);
double StandardDeviation(double grades[], int n);
void frequency(double grades[], int n);

int main(){
   double grades[100]; int count = 0;//empty array initialized to 0 to pass to function readGrades
   
   readGrades(grades, &count);
    
    /*for (int i = 0; i < count; i++){
        printf("%.2lf\n", grades[i]);
        }//printing the array for real grades*/
        
    int indexMin = minimum(grades, count);
    
    printf("The data has been adjusted by removing the minimum %.2lf\n", grades[indexMin]);
    deleteElement(grades, &count, indexMin);
    
    
    int indexMax = maximum(grades, count);
      
    printf("The data has been adjusted by removing the maximum %.2lf\n", grades[indexMax]);
    deleteElement(grades, &count, indexMax);
   
    double adjustedMean = mean(grades, count);
    printf("Adjusted mean is %.2lf\n", adjustedMean);
    double adjustedSD = StandardDeviation(grades, count);
    printf("Adjusted stanrdard deviation is %.2lf\n", adjustedSD);
   
    frequency(grades, count);
   
}

//this function reads in the grades that user inputs & counts data items read
void readGrades(double grades[], int *n){
    int i; int count = 0;
    for (i = 0; i < 100 ; i++){
        scanf("%lf", &grades[i]);

        if(grades[i] == -999)
            break;
    count++;
    }
    grades[100] = grades[count];
    if (grades[count] == -999){
        for (i = 0; i < count; i++){
            grades[i] = grades[i];
        }  
    }
    *n = count; //updates count variable to number of elements
    //printf("%d\n", *n) printing out the size of the new set array
}

// this function spots the maximum of grades & returns its index position
int maximum(double grades[], int n){
    int maximumElement  = grades[0]; int i; int index = 0;
    for (i = 1; i < n; i++){
        if (grades[i] > maximumElement){
            maximumElement = grades [i];
            index = i;
        }
    }
    return index;   // use this location for the voidElement function
}

// this function spots the minimum of grades & returns its index position
int minimum(double grades[], int n){
    // n would be count for size of grades array
    int minimumElement  = grades[0]; int index = 0;
    for (int i = 1; i < n; i++){
        if (grades[i] < minimumElement){
            minimumElement = grades [i];
            index = i;
        }
    }
    return index;   //use this location for the voidElement function
}

//this function uses the index positions of min & max to delete it from the grades array
//also decreases arrays size by one
void deleteElement(double grades[], int *n, int loc){ 
    int i;
    for (i = loc; i < *n - 1; i++){
            grades[i] = grades[i + 1];    
    }
             *n = *n - 1;  

    /*printf("\nGrades after deleting are : ");
        for(i = 0; i < *n; i++){
            printf("%f\t", grades[i]);
    }*///checking to see if grades actually deleted
    printf("\n");
}

//this function calculates the mean of the adjusted array 
double mean(double grades[], int n){
    double sum = 0;    
    for (int i = 0; i < n; i++){
        sum += grades[i];
    }
double mean = (sum)/n;
return mean;
}

//this function calculates the standard deviation using the sqrt & pow functions
double StandardDeviation(double grades[], int n){
    double m = mean(grades, n); double runningTotal = 0;
    for (int i = 0; i < n; i++){
        runningTotal += pow(grades[i] - m, 2);
    }
double quantity = runningTotal/n;
double sD = sqrt(quantity);

return sD;
}

//this function counts the frequency of the grades per every 5th interval & creates histogram
void frequency(double grades[], int n){
    int freq[21] = {0};

    for (int i = 0; i < n; i++){
        int index = grades[i] / 5;
        freq[index]++;
    }

    printf("\nHere is the histogram of the adjusted data: \n\n");

    for (int i = 0; i < 20; i++){
        printf("%2d - %2d|", i*5, i*5 + 4);
        for (int j = 0; j < freq[i]; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("    100|");
    for (int i = 0; i < freq[20]; i++){
        printf("*");
    }
    printf("\n");
}