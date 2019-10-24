#include<stdio.h>

int main()
{
      int m, n, numblock, numreq, temp, top = 0;
      printf("\nEnter the Total Number of Blocks:\t");
      scanf("%d",&numblock);
      printf("Enter the Total Number of Files:\t");
      scanf("%d",&numreq);
      printf("\nEnter the Size of the Blocks:\n");
      int frags[numblock], blocks[numblock], req[numreq];
      static int block_arr[10], reqar[10];
      for(m = 0; m < numblock; m++)
      {
            printf("Block No.[%d]:\t", m + 1);
            scanf("%d", &blocks[m]);
      }
      printf("Enter the Size of the Files:\n");
      for(m = 0; m < numreq; m++)
      {
            printf("File No.[%d]:\t", m + 1);
            scanf("%d", &req[m]);
      }
      for(m = 0; m < numreq; m++)
      {
            for(n = 0; n < numblock; n++)
            {
                  if(block_arr[n] != 1)
                  {
                        temp = blocks[n] - req[m];
                        if(temp >= 0)
                        {
                              if(top < temp)
                              {
                                    reqar[m] = n;
                                    top = temp;
                              }
                        }
                  }
                  frags[m] = top;
                  block_arr[reqar[m]] = 1;
                  top = 0;
            }
      }
      printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
      for(m = 0; m < numreq; m++)
      {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, req[m], reqar[m], blocks[reqar[m]], frags[m]);
      }
      printf("\n");
      return 0;
}
