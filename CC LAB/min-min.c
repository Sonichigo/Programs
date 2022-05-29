#include<stdio.h>
#include <limits.h>
int main(){
    int nT,nM;
printf("\nEnter number of machines and tasks\n");
scanf("%d%d",&nM,&nT);

int minMin[nM][nT];
int tmp[nM][nT];
int makespan=0;
printf("\nFill Data\n");
for(int i=0;i<nM;i++)
for(int j=0;j<nT;j++){
scanf("%d",&minMin[i][j]);
tmp[i][j]=minMin[i][j];
}
printf("\nOriginal Data\n");

for(int i=0;i<nM;i++){
for(int j=0;j<nT;j++)
printf("%d ",minMin[i][j]);
printf("\n");
}

int resultTask[nT];
int resultMachine[nT];
int resultTime[nT];
int ptr=-1; 

while(ptr<nT-1){
int time[nT],machine[nT];
for(int j=0;j<nT;j++){
int minimum = INT_MAX;
int pos=-1;
for(int i=0;i<nM;i++){
if(minMin[i][j]<minimum){
minimum=minMin[i][j];
pos=i;
}
}
time[j]=minimum;
machine[j]=pos;
}

int minimum=INT_MAX;
int pos=-1;

for(int j=0;j<nT;j++){
if(time[j]<minimum){
minimum=time[j];
pos=j;
}
}

resultTask[++ptr]=pos;
resultMachine[ptr]=machine[pos];
resultTime[ptr]=tmp[machine[pos]][pos];
if(minimum>makespan)
makespan=minimum;

for(int i=0;i<nM;i++){
for(int j=0;j<nT;j++){
if(j==resultTask[ptr])
minMin[i][j]=INT_MAX;
else if(i==resultMachine[ptr] && minMin[i][j]!=INT_MAX)
minMin[i][j]+=minimum;
else
continue;
}
}

}

printf("\nScheduled Task are :\n");
for(int i=0;i<nT;i++){
printf("\nTask %d Runs on Machine %d with Time %d units\n",resultTask[i]+1,resultMachine[i]+1,resultTime[i]);
}

printf("\nMakespan : %d units\n",makespan);
return 0;
}