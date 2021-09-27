#include <stdio.h>

int main()
{
  float numbers[1000],size=1000,highest,time,time_per_sample;   //declare all float variables//
  FILE *input_fptr;
  int i ;
  float frequency = 1/0.000001;                                   //loop counter//

time = 0.001*size;                                   //to calculate time use this equation//
time_per_sample = 0.001/1000;                        //to calculate time pre sample ude this//
                                               //open file//
  input_fptr = fopen("sinewave.csv", "r");
                                                //read 1000 numbers to an array//
  if(input_fptr != NULL)
  {
                                               //get input from a file//
         for(i=0; i<size; i++)
         {
             fscanf(input_fptr, "%f", & numbers[i]);      //scan numbers//
         }
         fclose(input_fptr);


                                                 // Get amplitude//
        highest = numbers[0];
        for (i=1; i<size; i++)
        {
            if(highest<numbers[i])               //compare the values//
              highest = numbers[i];              //save new value to highest//
        }
        printf(" The amplitude(highest) is  = %fV\n ",highest);
        printf("total number of samples is = %.2f\n",size);
        printf(" total time                 = %.1fs\n",time);
        printf(" period                     = %f\n",time_per_sample);
        printf("fequency is                 = %.2fHz",frequency             );    //use function to get frequency,f=1/priod//

   }
   else
   {
       printf("Error file not read");
   }
   return 0;
}












//total_time                                    = 0.001 s (1 ms)
//time_per_sample = total_time/number_of_samples = 0.000001 = 1e-6 s
//number_of_samples_per_cycle                     = 100
//period = number_of_samples_per_cycle x time_per_sample
//                                                 = 100 x 1e-6 = 0.0001 s
//frequency = 1/period =






