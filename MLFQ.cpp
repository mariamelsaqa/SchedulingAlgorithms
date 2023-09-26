
#include <iostream>
#include <queue>
using namespace std;


enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
struct proc {
    int pid; //process ID
    enum procstate state; //process state
    int arrivalTime;
    int execTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    int completionTime;
};


void Multi_Level_Feedback_Queue(int size, proc* processes);
void print_queue(queue<proc> q);

int main()
{
    for(int size = 2500; size<= 2900; size = size+ 100)
    {
     proc* process= new proc[size];
     for (int i = 0; i < size; i++)
     {
         process[i].pid = i + 1;
         process[i].execTime = 1 + (rand() % 100);
        // cout << process[i].pid << " " << process[i].execTime << endl;
     }
     float TATs = 0, RESs=0, Waits = 0;
     float TAT, RES, Wait;


    Multi_Level_Feedback_Queue(size, process);
    for (int i = 0; i < size; i++)
    {
      //  cout << "PROCESS " << process[i].pid << " TURNAROUND TIME = " << process[i].turnaroundTime << endl;
       // cout << "PROCESS " << process[i].pid << " RESPONSE TIME = " << process[i].responseTime << endl;
        //cout << "PROCESS " << process[i].pid << " WAITING TIME = " << process[i].waitingTime << endl;
        TATs = TATs + process[i].turnaroundTime;
        RESs = RESs + process[i].responseTime;
        Waits = Waits + process[i].waitingTime;
    }

    TAT = TATs / size;
    RES = RESs / size;
    Wait = Waits / size;
        cout << "For size : " << size << endl;
    cout << "TAT = " << TAT << endl << "RES = " << RES << endl << "Wait = " << Wait << endl;
    }



}
void Multi_Level_Feedback_Queue(int size, proc* processes)
{//implementing 5 queues
    queue<proc>q[5];
    int quantum[5] = { 4,8,16,32,64 };
    bool executing[5] = { false,false,false,false,false };
    proc running_proc[5];
    int proc_time[5];
    for (int i = 0; i < size; i++)
        q[0].push(processes[i]);
    int time = 0;
    for (int i = 0; i < size; i++)
        processes[i].waitingTime = 0;
    while ((q[0].size() > 0) || (q[1].size() > 0) || (q[2].size() > 0) || (q[3].size() > 0) || (q[4].size() > 0) || (executing[0] == true) || (executing[1] == true) || (executing[2] == true) || (executing[3] == true) || (executing[4] == true))
    {

        //cout << "CYCLE NUMBER " << time << endl;
        for (int i = 0; i < 5; i++)
        {

            if (!executing[i])
            {
                if (q[i].size() > 0)
                {
                    running_proc[i] = q[i].front();
                    q[i].pop();
                    running_proc[i].state = RUNNING;
                    for (int j = 0; j < size; j++)
                        if (running_proc[i].pid == processes[j].pid)
                            processes[j].responseTime = time;
                    proc_time[i] = 0;
                    executing[i] = true;
                }
            }
            else
            {
                if ((proc_time[i] == quantum[i]) && (i != 4))
                {

                    proc_time[i] = 0;
                    running_proc[i].state = RUNNABLE;
                    executing[i] = false;
                    q[i + 1].push(running_proc[i]);
                }
                else if (running_proc[i].execTime == 0)
                {
                    executing[i] = false;
                    running_proc[i].state = ZOMBIE;
                    for (int j = 0; j < size; j++)
                        if (running_proc[i].pid == processes[j].pid)
                        {
                            processes[j].turnaroundTime = time;
                           // cout << processes[j].pid << " IS OUT" << endl;
                        }


                }
                else
                {
                    proc_time[i]++;
                    running_proc[i].execTime--;
                }
            }

            //  cout << endl;
            //print_queue(q[i]);
            //cout << "     proc running:  " << running_proc[i].pid << "|  Time spent running: " << proc_time[i] << endl;
        }
        time++;
        for (int i = 0; i < 5; i++)
        {
            if (q->empty() != true)
                for (size_t j = 0; j < q[i].size(); j++)
                {
                    for (int k = 0; k < size; k++)
                        if (q[i].front().pid == processes[k].pid)
                            processes[k].waitingTime++;
                    q[i].push(q[i].front());
                    q[i].pop();
                }
        }
    }
}

void print_queue(queue<proc> q)
{
    if (q.empty())
        cout << "EMPTY";
    for (size_t i = 0; i < q.size(); i++)
    {
        cout << q.front().pid << " |";
        q.push(q.front());
        q.pop();
    }
}
