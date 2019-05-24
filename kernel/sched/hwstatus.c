/*
 * kernel/sched/hwstatus.c
 *
 * Copyright(C) 2018, Huawei, Inc., hwfatboy
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/seq_file.h>
#include <linux/kallsyms.h>
#include <linux/utsname.h>
#include <linux/mempolicy.h>

#include <asm/barrier.h>
#include <asm/stacktrace.h>
#include <asm/irq.h>

#include "sched.h"

#define SEQ_printf(m, x...)			\
 do {						\
	if (m)					\
		seq_printf(m, x);		\
	else					\
		printk(x);			\
 } while (0)

#define SPLIT_NS(x) nsec_high(x), nsec_low(x)

#define PN(F) \
        SEQ_printf(m,"  .%-30s: %lld.%06ld\n",#F, SPLIT_NS((long long )F))

#define FGTASK_MAX 4
#define M_IODELAY_VALUE  (300*1000*1000)
#define CALLER_NAME_LEN  256
#define M_DSDELAY_VALUE  (200*1000*1000)
#define STACK_DUMP_SIZE  1024

enum{
	FG_UI = 0,
	FG_RENDER,
	PREV_UI,
	PREV_RENDER
};

enum{
	VERSION_V1 = 1,
	VERSION_V2 = 2,
	VERSION_V3,
};

typedef struct sched_hwstatus_rsthead
{
	u64 ktime_last;
	u64 ktime_now;
}sched_hwstatus_rsthead;

typedef struct hwstatus_mem
{
	u64 allocuser_delay;
	u64 allocuser_count;
	u64 allocuser_delay_max;
	u64 allocuser_delay_max_order;
}hwstatus_mem;

typedef struct hwstatus_caller
{
	u64  ktime_iodelay;
	char caller_iodelay[CALLER_NAME_LEN];
}hwstatus_caller;

typedef struct hwstatus_stack
{
	char	stack[STACK_DUMP_SIZE];
}hwstatus_stack;

typedef struct sched_hwstatus_rstbody
{
	pid_t pid;
	pid_t tgid;
	sched_hwstatus hwstatus;
}sched_hwstatus_rstbody;

typedef struct sched_hwstatus_rst_V1
{
	sched_hwstatus_rsthead head;
	sched_hwstatus_rstbody body[FGTASK_MAX];
}sched_hwstatus_rst_V1;

typedef struct sched_hwstatus_rst_V2
{
	sched_hwstatus_rsthead head;
	sched_hwstatus_rstbody body[FGTASK_MAX];
	hwstatus_mem           mem[FGTASK_MAX];
	hwstatus_caller        caller;
}sched_hwstatus_rst_V2;

typedef struct sched_hwstatus_rst_V3
{
	sched_hwstatus_rsthead head;
	sched_hwstatus_rstbody body[FGTASK_MAX];
	hwstatus_mem           mem[FGTASK_MAX];
	hwstatus_caller        caller;
	hwstatus_stack         stack;
}sched_hwstatus_rst_V3;

typedef sched_hwstatus_rst_V3 sched_hwstatus_rst;

void sched_hwstatus_iodelay_caller(struct task_struct *tsk, u64 delta)
{
}

void sched_hwstatus_updatefg(pid_t pid, pid_t tgid)
{
}

static ssize_t sched_hwstatus_read(struct file* file, char __user *buf,
			size_t count, loff_t *ppos)
{
	return 0;
}



static ssize_t sched_hwstatus_write(struct file *file, const char __user *buf,
			size_t count, loff_t *ppos)
{
	return 0;
}

static const struct file_operations sched_hwstatus_fops = {
	.read		= sched_hwstatus_read,
	.write		= sched_hwstatus_write,
};

static int __init init_sched_hwstatus_procfs(void)
{
	return 0;
}

__initcall(init_sched_hwstatus_procfs);
