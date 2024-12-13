## MLFQ Scheduling
ECE 6045: Operating Systems Engineering
George Washington University
Isaac Bilsel

The goal of this project was to implement a Multi-level Feedback Queue (MLFQ) to replace the Round Robin scheduler used in Xv6. The major changes are listed below. 

#### proc.h file 
- *struct proc_table:* A new struct was added, which stores an array of queues, the allotment of each queue, and the total number of processes. 
- *struct proc:* This struct was augmented to include the priority of each process, the allotment (time it has left at that priority level), and the place in the priority queue. 
#### proc.c file
- *scheduler(void):* The new scheduler function only loops through the ready queues, the new scheduling time is O(runnable processes)
- *procinit(void):* Initialize the proc_table struct, named ptable and set allotment values
- *allocproc(void):* Once initialized, the process is placed in the highest priority queue
- *yield():* This function was augmented to take an input (int inter) that represents whether the process is yielding voluntarily or on clock interrupt. The logic moving the process down in the ptable is also included here. 
- *scheduler():* Simple changes are made to the scheduler function so that the main loop is infinitely iterating through the ptable (the MLFQ) instead of the proc[] array as in the vanilla Xv6. 
- *priorityboost():* This function is called by clockintr() in trap.c. If the current tick count is divisible by the parameter, BOOST. When called, loops through all processes in the ptable. For each process, the proc pointer is removed from the current (lower) queue and the proc is allocated to the top priority queue with associated allotment value. 
- *rmv_proc():* Helper function added to remove the proc pointer from the queue to prevent queue overflow. 
#### trap.c file
- *usertrap():* This function was modified to handle clock interrupts, which occur at the same frequency as the top queue allotment, MINSLICE. The proc’s allotment is reduced by MINSLICE at each interrupt, and if this causes the allotment to be == 0, the process calls yield with intr argument identifying that it is a clock interrupt. 
#### sysproc.c
- *sys_printmlfq():* System call to display MLFQ contents
#### mlfqtest.c
- This testing script creates an artificial workload to test the MLFQ by calling fork() and spinning at each child.




#### BUILDING AND RUNNING XV6

You will need a RISC-V "newlib" tool chain from
https://github.com/riscv/riscv-gnu-toolchain, and qemu compiled for riscv64-softmmu.  Once they are installed, and in your shell search path, you can run "make qemu".

exit shell: ctrl + A --> C --> q
view processes: ctrl + p
