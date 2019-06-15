#include <linux/kernel.h>

void iowp_report(pid_t pid , pid_t tgid, char* name);
void iowp_workqueue_init(void);
void iowp_report(pid_t pid , pid_t tgid, char* name) {}
void iowp_workqueue_init(void) {}
