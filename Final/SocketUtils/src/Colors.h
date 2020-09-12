/*
 * Colors.h
 *
 *
 * Author: Nati the painter
 */
#ifndef COLORS_H_
#define COLORS_H_

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST // Red
#define FGRN(x) KGRN x RST // Green
#define FYEL(x) KYEL x RST // Yellow
#define FBLU(x) KBLU x RST // Blue
#define FMAG(x) KMAG x RST // Purple
#define FCYN(x) KCYN x RST // Light Blue
#define FWHT(x) KWHT x RST // White

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST


#endif /* COLORS_H_ */
