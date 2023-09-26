////
////  main.c
////  Lab9
////
////  Created by Mariam Elsaqa on 09/04/2022.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <string.h>
//
////#define NPROC 2900
//
//typedef struct{
//    int BurstTime;
//    int Arrivaltime;
//    int waitingTime;
//    int TurnaroundTime;
//    int ResponseTime;
//}process;
//
//int GetMin (process* p, int NPROC){
//    int min;
//
//    min = p[0].BurstTime;
//
//    for (int i = 1; i < NPROC; i++) {
//       if(p[i].BurstTime < min)
//           min = p[i].BurstTime;
//    }
//
//    return min;
//}
//
//int GetMax (process* p, int NPROC){
//    int max;
//
//    max = p[0].BurstTime;
//
//    for (int i = 1; i < NPROC; i++) {
//       if(p[i].BurstTime > max)
//           max = p[i].BurstTime;
//    }
//
//    return max;
//}
//
//void RoundRobin(process* p,int TimeSlice, int NPROC){
//    int tempBT[NPROC];
//
//    for (int i=0; i<NPROC; i++) {
//        tempBT[i] = p[i].BurstTime;
//    }
//
//    int Time = 0;
//    int flag = 0;
//    double totalWT = 0, totalTAT = 0, totalRT = 0;
//
//    while (flag == 0) {
//        flag = 1;
//
//        for (int i=0; i<NPROC; i++) {
//            if (tempBT[i] > 0){
//                flag = 0;
//
//                if(tempBT[i] > TimeSlice){
//                    Time += TimeSlice;
//                    tempBT[i] -= TimeSlice;
//                }
//                else{
//                    Time += tempBT[i];
//                    p[i].waitingTime = Time - p[i].BurstTime;
//                    tempBT[i] = 0;
//                }
//            }
//            p[i].TurnaroundTime = p[i].waitingTime + p[i].BurstTime;
//        }
//    }
//
//
//    p[0].ResponseTime = 0;
//    for (int i=1; i<NPROC; i++) {
//        if(p[i-1].BurstTime > TimeSlice)
//            p[i].ResponseTime = p[i-1].ResponseTime + TimeSlice;
//        else
//            p[i].ResponseTime = p[i-1].ResponseTime + p[i-1].BurstTime;
//    }
//
//
//    printf("\%d -> Round Robin Scheduling: \n", NPROC);
////    printf("P\t\tWT\t\tTAT\t\tRT\n");
//    for (int i=0; i<NPROC; i++) {
////        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,
////            p[i].waitingTime,
////            p[i].TurnaroundTime,
////            p[i].ResponseTime
////            );
//        
//        totalWT += p[i].waitingTime;
//        totalTAT += p[i].TurnaroundTime;
//        totalRT += p[i].ResponseTime;
//    }
//
//        printf("Average Waiting Time= %.2f\n",totalWT/NPROC);
//        printf("Avg Turnaround Time = %.2f\n",totalTAT/NPROC);
//        printf("Avg Response Time = %.2f\n\n\n",totalRT/NPROC);
//
//
//}
//
//void FCFS (process* p, int NPROC){
//    p[0].waitingTime = 0;
//    p[0].TurnaroundTime = p[0].BurstTime;
//    p[0].ResponseTime = 0;
//    for (int i=1; i<NPROC; i++) {
//        p[i].waitingTime = p[i-1].BurstTime + p[i-1].waitingTime;
//        p[i].TurnaroundTime = p[i].BurstTime + p[i].waitingTime;
//        p[i].ResponseTime = p[i-1].ResponseTime+ p[i-1].BurstTime;
//    }
//
//    double totalWT = 0, totalTAT = 0,  totalRT = 0;
//
//    printf("\%d -> FCFS Scheduling: \n", NPROC);
////    printf("P\t\tWT\t\tTAT\t\tRT\n");
//    for (int i=0; i<NPROC; i++) {
////        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,
////            p[i].waitingTime,
////            p[i].TurnaroundTime,
////            p[i].ResponseTime
////            );
//
//        totalWT += p[i].waitingTime;
//        totalTAT += p[i].TurnaroundTime;
//        totalRT += p[i].ResponseTime;
//    }
//
//        printf("Average Waiting Time= %.2f\n",totalWT/NPROC);
//        printf("Avg Turnaround Time = %.2f\n",totalTAT/NPROC);
//        printf("Avg Response Time = %.2f\n\n\n\n\n",totalRT/NPROC);
//
//}
//
//int main(int argc, const char * argv[]) {
//    int NPROC;
//    process* p = (process*) malloc(NPROC*4);;
//    int TimeSlice = 30;
//    for(int i = 900; i<= 2900; i+=100){
//        NPROC = i;
//
//        for (int i = 0; i <NPROC; i++)
//        {
//            p[i].BurstTime = rand()%100+1;
//         }
////        printf("min = %d , max = %d\n", GetMin(p, NPROC) , GetMax(p, NPROC));
////        printf("Time slice = %d or %d\n", (int)(0.3*GetMax(p, NPROC)) , (int)(0.4*GetMax(p, NPROC)));
//
////        int TimeSlice;
////        printf("Enter the timeSlice\n");
////        //TimeSlice = atoi(argv[1]);
////        scanf("%d",&TimeSlice);
//        while (TimeSlice < GetMin(p, NPROC) || TimeSlice > GetMax(p, NPROC) || TimeSlice >= (int)(0.5*GetMax(p, NPROC)) || TimeSlice <= (int)(0.2*GetMax(p, NPROC))) {
//            printf("Time Slice is not suitable\n");
//            scanf("%d",&TimeSlice);
//        }
//
//        RoundRobin(p, TimeSlice, NPROC);
//        FCFS(p, NPROC);
//
//    }
//    free(p);
//    return 0;
//}
