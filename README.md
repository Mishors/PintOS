# PintOS - Threads phase 

Pintos is a simple operating system framework for the 80x86 architecture. It supports kernel threads, loading and running user programs, and a file system, but it implements all of these in a very simple way. Pintos could, theoretically, run on a regular IBM-compatible PC. Unfortunately, it is impractical to supply every student a dedicated PC for use with Pintos. Therefore, we will run Pintos projects in a system simulator, that is, a program that simulates an 80x86 CPU and its peripheral devices accurately enough that unmodified operating systems and software can run under it. Bochs and QEMU simulators are used to run Pintos.   

## Threads Phase Overview

In this phase 3 parts of PintOS have been implemented or reimplemented to support more efficiency and good performance. The 3 parts are System Alarm clock, Priority Scheduler and Advanced Scheduler.


### Alarm Clock

```timer_sleep()``` function is reimplemented to avoid busy waiting and spinning in a loop checking the current time and calling ```thread_yield()``` until enough time has gone.

### Priority Scheduler

Threads are given priorites.Then a thread is added to the ready list that has a higher priority than the currently running thread, the current thread should immediately yield the processor to the new thread. Similarly, when threads are waiting for a lock, semaphore, or condition variable, the highest priority waiting thread should be awakened first. A thread may raise or lower its own priority at any time, but lowering its priority such that it no longer has the highest priority must cause it to immediately yield the CPU. 

Priority inversion situations is handelled in the scheduler.Consider high, medium, and low priority threads H, M, and L, respectively. If H needs to wait for L (for instance, for a lock held by L), and M is on the ready list, then H will never get the CPU because the low priority thread will not get any CPU time. The technique used to solve this issue is **priority donation**.


### Advanced Scheduler

Multilevel feedback queue scheduler which is similar to the BSD scheduler to reduce the average response time for running jobs on the system.

Like the priority scheduler, the advanced scheduler chooses the thread to run based on priorities. However, the advanced scheduler does not do priority donation.

Advanced Scheduler uses equations to calculate some values that make it take the decisions for example :
* ![](https://latex.codecogs.com/gif.latex?priority%20%3D%20PRI%5C_MAX%20-%20%28%5Cfrac%7Brecent%5C_cpu%7D%7B4%7D%29%20-%20%28nice%20*%202%29) 
* ![](https://latex.codecogs.com/gif.latex?recent%5C_cpu%20%3D%20%5Cfrac%7B2*load%5C_avg%7D%7B2*load%5C_avg%20&plus;%201%7D%20*%20recent%5C_cpu%20&plus;%20nice)
* ![](https://latex.codecogs.com/gif.latex?load%5C_avg%20%3D%20%5Cfrac%7B59%7D%7B60%7D*load%5C_avg%20&plus;%20%5Cfrac%7B1%7D%7B60%7D*ready%5C_threads)


