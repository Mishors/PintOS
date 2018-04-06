# PintOS - Threads phase 

Pintos is a simple operating system framework for the 80x86 architecture. It supports kernel threads, loading and running user programs, and a file system, but it implements all of these in a very simple way. Pintos could, theoretically, run on a regular IBM-compatible PC. Unfortunately, it is impractical to supply every student a dedicated PC for use with Pintos. Therefore, we will run Pintos projects in a system simulator, that is, a program that simulates an 80x86 CPU and its peripheral devices accurately enough that unmodified operating systems and software can run under it. Bochs and QEMU simulators are used to run Pintos.   

## Threads Phase Overview

In this phase 3 parts of PintOS have been implemented or reimplemented to support more efficiency and good performance. The 3 parts are System Alarm clock, Priority Scheduler and Advanced Scheduler.


### Alarm Clock

```timer_sleep()``` function is reimplemented to avoid busy waiting and spinning in a loop checking the current time and calling ```thread_yield()``` until enough time has gone.

### Priority Scheduler

Threads are given priorites.Then a thread is added to the ready list that has a higher priority than the currently running thread, the current thread should immediately yield the processor to the new thread. Similarly, when threads are waiting for a lock, semaphore, or condition variable, the highest priority waiting thread should be awakened first. A thread may raise or lower its own priority at any time, but lowering its priority such that it no longer has the highest priority must cause it to immediately yield the CPU. 

Priority inversion situations is handelled in the scheduler.Consider high, medium, and low priority threads H, M, and L, respectively. If H needs to wait for L (for instance, for a lock held by L), and M is on the ready list, then H will never get the CPU because the low priority thread will not get any CPU time. The technique used to solve this issue is **Priority donation**.


### Advanced Scheduler

Multilevel feedback queue scheduler which is similar to the BSD scheduler to reduce the average response time for running jobs on the system.

Like the priority scheduler, the advanced scheduler chooses the thread to run based on priorities. However, the advanced scheduler does not do priority donation.

Advanced Scheduler uses equations to calculate some values that make it take the decisions for example :
* $\ Priority = PRI_MAX - frac{recent_cpu}{4} - (nice * 2)


