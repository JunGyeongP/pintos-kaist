#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

struct box {
    struct file *file;
    off_t ofs;
    size_t page_read_bytes;
};


tid_t process_create_initd (const char *file_name);
tid_t process_fork (const char *name, struct intr_frame *if_);
int process_exec (void *f_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (struct thread *next);
struct thread *get_child(int pid);




// (+ Project 3)
bool install_page (void *upage, void *kpage, bool writable);
bool setup_stack (struct intr_frame *if_);
#endif /* userprog/process.h */
