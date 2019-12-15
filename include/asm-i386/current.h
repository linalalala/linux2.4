#ifndef _I386_CURRENT_H
#define _I386_CURRENT_H

struct task_struct;

static inline struct task_struct * get_current(void)
{
	struct task_struct *current;

	/**
		将ESP的内容与8191UL的反码按位进行与操作，之后再把结果赋值给current，其中8191UL=8192-1=2^13-1
		

	**/
	__asm__("andl %%esp,%0; ":"=r" (current) : "0" (~8191UL));
	return current;
 }
 
#define current get_current()

#endif /* !(_I386_CURRENT_H) */
