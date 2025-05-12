/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"
#include <math.h>

/* Size of the Data Set */
#define SIZE (40)

void print_array(unsigned char *array, unsigned int length) {
  for (int i = 0; i < length; i++) {
      printf("%d ", array[i]);  // Print each element as an integer
  }
  printf("\n");  // Print a newline after the array
}





void print_statistics(unsigned char *array, unsigned int length){
  unsigned char min = find_minimun(array, length) 
  unsigned char max = find_maximum(array, length)   
  unsigned char mean = find_mean(array, length)  
  float median = find_median(array, length)
  
  
  printf("Statistics:\n");
    printf("Minimum: %u\n", min);
    printf("Maximum: %u\n", max);
    printf("Mean:    %u\n", mean);
    printf("Median:  %.2f\n", median);
};

void sort_array(unsigned char *array, unsigned int length) {
  for (int i = 0; i < length - 1; i++) {
      for (int j = 0; j < length - i - 1; j++) {
          if (array[j] > array[j + 1]) { 
              unsigned char temp = array[j];
              array[j] = array[j + 1];
              array[j + 1] = temp;
          }
      }
  }
}


float find_median(unsigned char *array, unsigned int length){
  sort_array(array, length)

  if(length%2 == 0){/*even length*/
    float median = array[length/ 2 - 1] + array[length/2 ] / 2.0
    return median
  } else {
    float median = array[length/2]
    return median
  }
};



unsigned char find_maximum(unsigned char *array, unsigned int length){

  unsigned char max = array[0];
  for(int i = 1 ; i < length; i++){
    
    if(array[i] > max ){
      max = array[i];
    } 
  
  
  }

  return max;
};



unsigned char find_minimum(unsigned char *array, unsigned int length){

  unsigned char min = array[0];
  for(int i = 1 ; i < length; i++){
    
    if(array[i] < min ){
      min = array[i];
    } 
  
  
  }

  return min;
};



float find_mean(unsigned char *array, unsigned int length){
  unsigned int total = 0;
  for(int i = 0 ; i < length; i++){
    total += array[i] ;
  }

  unsigned char mean = total / length ;

  return mean;
};

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test, SIZE);
  print_statistics(test, SIZE);

  sort_array(test, SIZE);
  find_median(test, SIZE);
  find_maximum(test, SIZE);
  find_minimum(test, SIZE);
  find_mean(test, SIZE);

}

/* Add other Implementation File Code Here */
