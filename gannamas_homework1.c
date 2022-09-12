#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define FLT_MIN 1.175494351e-38F

int uniquedegree(char degree[][50],int n)
{
    int i, j, count = 1;
    char unique[n][50];
   strcpy(unique[0],degree[1]);
   for (i = 2; i < n; i++)    
   {
      for (j = 1; j < i; j++)   
      {
         if (strcmp(degree[i],degree[j]))  ; 
         else
         break;
      }
      if (i == j)
      {
        strcpy(unique[count],degree[i]);
         count=count+1; 
        
            
      }
   }

   printf("we are having %d unique degrees,they are\n",count);
   for(i=0;i<count;i++)
   printf("%s\n",unique[i]);
   return 0;

}
int topthreestudents(char firstname[][50],char lastname[][50],float gpa[],int n)
{
    float firstrank, secondrank, thirdrank;
    int i,f,s,t=0;

 
    thirdrank = firstrank = secondrank = FLT_MIN;
    for (i = 1; i <n; i++) {
       
        if (gpa[i] > firstrank) {
            thirdrank = secondrank;
            t=s;
            secondrank = firstrank;
            s=f;
            firstrank = gpa[i];
            f=i;
        }
        else if (gpa[i] > secondrank) {
            thirdrank = secondrank;
            t=s;
            secondrank = gpa[i];
            s=i;
        }
 
        else if (gpa[i] > thirdrank)
        {
            thirdrank = gpa[i];
            t=i;
        }
            
    }
 
   // printf("\nThree largest elements are %f %f %f\n", firstrank, secondrank, thirdrank);
    printf("\n%s %s is in top three with %f\n",firstname[f],lastname[f],firstrank);
    printf("%s %s is in top three with %f\n",firstname[s],lastname[s],secondrank);
    printf("%s %s is in top three with %f\n",firstname[t],lastname[t],thirdrank);

  
  return 0;
}

int averagecredithours(int credits[],int n)

{
  int i;
  float avgcredithour=0;
  for (i=1;i<n;i++)
  avgcredithour=avgcredithour+credits[i];
  avgcredithour=avgcredithour/(n-1);
  printf("\naverage credit hours of college is %f\n",avgcredithour);

  return 0;
}

int averagegpaofcs(float gpa[],char major[][50],int n)
{
  int i,count=0;
  float avggpa=0;
  for(i=1;i<n;i++)
  {
    if(strcmp(major[i],"Computer Science"));
    else
    { 
      //printf("%f\n",gpa[i]);
      count=count+1;
      avggpa=avggpa+gpa[i];

    }
  }
  //printf("%d\n",count);
  avggpa=avggpa/count;
  printf("\naverage gpa of computer science students is %f\n",avggpa);
  return 0;
}
int helperadv(char majoradvisor[][50],int n)
{
   int i, j, count = 1;
  char unique[n][50];
   strcpy(unique[0],majoradvisor[0]);
   for (i = 1; i <n; i++)    
   {
      for (j = 0; j < i; j++)   
      {
         if (strcmp(majoradvisor[i],majoradvisor[j]))  ; 
         else
         break;
      }
      if (i == j)
      {
        strcpy(unique[count],majoradvisor[i]);
         count=count+1; 
        
            
      }
   }

  return count;
}
int advisorlist(char major[][50],char advisor[][50],int n)
{
   int i, j, count = 1;
   char unique[n][50];
   strcpy(unique[0],major[1]);
   printf("\n");
   for (i = 2; i < n; i++)    
   {
      for (j = 1; j < i; j++)   
      {
         if (strcmp(major[i],major[j]))  ; 
         else
         break;
      }
      if (i == j)
      {
        strcpy(unique[count],major[i]);
         count=count+1; 
        
            
      }
   }
   int frequency,
   c=0;
   for(i=0;i<count;i++)
   {
  
    char majoradvisor[100][50];
    for(j=1;j<n;j++)
    { 
      
       if(strcmp(major[j],unique[i]));
       else
       {
       strcpy(majoradvisor[c],advisor[j]);
       c=c+1;
       }
       
    }





    frequency=helperadv(majoradvisor,c);
    printf("%s contains %d advisors\n",unique[i],frequency);
    c=0;


   }

   return 0;
}

static const char filename[] = "students_dataset.csv";
int main() 
{
    char firstname[100][50];
    char lastname[100][50];
    char major[100][50];
    char degree[100][50];
    float gpa[100];
    int credits[100];
    char ta[100][10];
    char advisor[100][50];


    FILE *file = fopen(filename, "r");
    int i=0;
    char* sp;
    int size;
    float gp;
    int credit;

    if ( file != NULL )
    {   
        char line[500];
        while (fgets(line, sizeof line, file) != NULL) /* read a line */
        {   
          if(i==0)
          {
            i=i+1;
            continue;
          }
         
    
          sp=strtok(line,",");
          strcpy(firstname[i],sp);
          sp=strtok(NULL,",");
          strcpy(lastname[i],sp);
          sp=strtok(NULL,",");
          strcpy(major[i],sp);
          sp=strtok(NULL,",");
          strcpy(degree[i],sp);
          sp=strtok(NULL,",");
          gp=atof(sp);
          gpa[i]=gp;
          sp=strtok(NULL,",");
          credit=atoi(sp);
          credits[i]=credit;
          sp=strtok(NULL,",");
          strcpy(ta[i],sp);
          sp=strtok(NULL,",");
          strcpy(advisor[i],sp);

          i=i+1;
           
           
        }   
        size=i;
  
        
    
        uniquedegree(degree,size);
        topthreestudents(firstname,lastname,gpa,size);
        averagecredithours(credits,size);
        averagegpaofcs(gpa,major,size);
        advisorlist(major,advisor,size);

        fclose(file);
    }   

return 0;

}