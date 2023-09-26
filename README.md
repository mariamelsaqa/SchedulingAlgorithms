# SchedulingAlgorithms

####Implementation of Round Robin and First Come First Serve:
- Round Robin

If the process’ burst time is more than the time slice, the total time should be incremented with the value of the time slice and and the burst time should be decremented with the value of the time slice, then the process is marked as not completed.
But if the process’s burst time is less than or equal time slice, the total time will be incremented with the value of the burst time of the process (as it can be less than the time slice) and the waiting time is only calculated here as it is where the process will be done, and the burst time will be zero.

-> waiting time = totalTime – burst time

-> turnaround time = waiting time + burst time

->response time = response time of the previous process – (time slice or burst time)


- First Come First Serve

The first process to arrive is the first process to begin execution. The waiting and the response time of the first process is always zero as it will not wait at all.
Each process wait for the previous process to finish to start execution.

-> waiting time = waiting time of the previous process + burst time of the previous process 

-> turnaround time = waiting time + burst time

->response time = response time of the previous process –burst time of the previous process 



These 2 algorithms are implemented in the same C file.

In a seperate C file There is the implemetaion of 
####Multilevel Feedback Queue Scheduling.

It contains 5 queues, where each queue has a quantum of (4,8,16,32,64) respectively. We also declare a process for each queue which resembles the process being executed by the queue aswell as a boolean variable for each queue whether the process is being executed or not. We first start by populating the first queue with all the process, then we start the scheduler by creating a while loop that keeps looping aslong as the queues aren't empty and are still executing a process. Each queue has 4 states, either it isn't executing a process, in which case it will pop from its queue a process and start executing(which will assign the response time if in the first queue)

The second state is that the process has finished its quantum time, in which case the queue will no longer be executing and will push the process to its following queue. The third state is that the process itself has finished, in which case it will assign the turnaround time and no longer be executing the process. The 4th state is that the queue is executing the process, in which case it will decrement the execution time remaining and increment the process quantum consumed. Every queue will go through one of these 4 states in each cycle (each cycle is represented as a loop). Finally, after every cycle, we will loop over all the 5 queues, and increment the waiting time for every process in those queue by 1 since they are in the RUNNABLE state. A process that has not finished and is in the 5th queue will stay in the 5th queue until it is completed.

Process Attributes:

Burst Time: It is an input that is needed in all algorithms

Arrival Time: It determines the order of the processes’ execution

Waiting Time: every process has its own waiting time which is computed

Turnaround Time: every process has its own turnaround time which is computed

Response Time: every process has its own response time which is computed

Completion Time: It helps in computing the response time.

