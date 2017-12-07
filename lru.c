#include<stdio.h>

int main(){
    int f,pf=0,n,m[20],flag[25],rs[25],i,j,count[20],next=1,min;
    printf("Enter the length of ref string\n");
    scanf("%d",&n);
    printf("Enter the reference string\n");
    for(i=0;i<n;i++){
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the no. of frames\n");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        m[i]=-1;
        count[i]=0;
    }
    /* page replacement process */
    for(i=0;i<n;i++){
        for(j=0;j<f;j++){
            if(m[j]==rs[i]){
                flag[i]=1;
                count[j]=next;
                next++;
            }
        }
        if(flag[i]==0){
            if(i<f){ /* check if the frames are free */
                m[i]=rs[i];
                count[i]=next;
                next++;
            }
            else{
                /* replace page */
                min=0;
                for(j=1;j<f;j++){
                    if(count[min]>count[j]){
                        min=j;
                    }
                }
                m[min]=rs[i];
                count[min]=next;
                next++;
            }
            pf++;
        }
        if(flag[i]==0){
            for(j=0;j<f;j++)
                printf("%d\t",m[j]);
            printf("PF no. = %d\n",pf);
            printf("\n");
        }
    }
    printf("Total no. of page faults = %d\n",pf);    
    return 0;
}