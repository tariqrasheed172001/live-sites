/*AIM: Given the common fixed-size buffer, 
the task is to make sure that the producer can’t 
add data into the buffer when it is full and the 
consumer can’t remove data from an empty buffer.*/

/*ALGORITHEM: The producer is to either go to sleep
 or discard data if the buffer is full. The next 
 time the consumer removes an item from the buffer, 
 it notifies the producer, who starts to fill the 
 buffer again. In the same manner, the consumer can 
 go to sleep if it finds the buffer to be empty. 
 The next time the producer puts data into the buffer, 
 it wakes up the sleeping consumer.*/ 


#include <stdio.h>
#include <stdlib.h>
  

int mutex = 1;
  

int full = 0;
  


int empty = 10, x = 0;
  

void producer()
{
   
    --mutex;
  
   
    ++full;
  
    
    --empty;
  
   
    x++;
    printf("\nProducer produces item %d",x);
    ++mutex;
}

void consumer()
{
   
    --mutex;
  
    
    --full;
  
    
    ++empty;
    printf("\nConsumer consumes "
           "item %d",
           x);
    x--;
  

    ++mutex;
}
  

int main()
{
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

#pragma omp critical
  
    for (i = 1; i > 0; i++) {
  
        printf("\nEnter your choice:");
        scanf("%d", &n);
  
        
        switch (n) {
        case 1:
  
            
            if ((mutex == 1)
                && (empty != 0)) {
                producer();
            }
  
            else {
                printf("Buffer is full!");
            }
            break;
  
        case 2:
  
            
            if ((mutex == 1)
                && (full != 0)) {
                consumer();
            }
  
            
            else {
                printf("Buffer is empty!");
            }
            break;
  

        case 3:
            exit(0);
            break;
        }
    }
}