/*
 * FCRON - periodic command scheduler 
 *
 *  Copyright 2000 Thibault Godouet <sphawk@free.fr>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 *  The GNU General Public License can also be found in the file
 *  `LICENSE' that comes with the fcron source distribution.
 */

 /* $Id: fcron.h,v 1.2 2000-05-15 18:28:39 thib Exp $ */

#ifndef __FCRONH__
#define __FCRONH__

#include "global.h"

#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <sys/ioctl.h>
#include <sys/time.h>


/* global variables */
extern char debug_opt;
extern char foreground;
extern char *cdir;
extern int daemon_uid;
extern pid_t daemon_pid;
extern char *prog_name;
extern char sig_hup;
extern CF *file_base;
extern int jobs_running;
/* end of global variables */


/* functions prototypes */

/* fcron.c */
extern void xexit(int exit_value);
/* end of fcron.c */

/* log.c */
extern void xcloselog(void);
extern char *make_msg(char *fmt, va_list args);
extern void explain(char *fmt, ...);
extern void explain_e(char *fmt, ...);
extern void warn(char *fmt, ...);
extern void warn_e(char *fmt, ...);
extern void error(char *fmt, ...);
extern void error_e(char *fmt, ...);
extern void die(char *fmt, ...);
extern void die_e(char *fmt, ...);
extern void Debug(char *fmt, ...);
/* end of log.c */

/* subs.c */
extern int remove_blanks(char *str);
extern char *strdup2(const char *);
/* end of subs.c */

/* database.c */
extern void test_jobs(time_t t2);
extern void wait_chld(void);
extern void wait_all(int *counter);
extern time_t time_to_sleep(short lim);
extern void set_next_exe(CL *line, char is_new_line);
extern void update_time_remaining(long dt);
/* end of database.c */

/* conf.c */
extern void reload_all(const char *dir_name);
extern void synchronize_dir(const char *dir_name);
extern void delete_file(const char *user_name);
extern void save_file(CF *file_name, char *path);
/* end of conf.c */

/* job.c */
extern void run_job(CF *file, CL *line);
extern void end_job(CF *file, CL *line, int status);
extern void end_mailer(CL *line, int status);
/* end of job.c */


#endif /* __FCRONH */
