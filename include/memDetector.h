
/*
 * memDetector.h
 *
 * */


#ifndef __MEM_DETECTOR__INTERFACE_H__
#define __MEM_DETECTOR__INTERFACE_H__

#define USE_MEM_DETECTOR

#ifdef USE_MEM_DETECTOR
// malloc

extern void* debug_malloc(char*, int,int);
extern void  debug_free(char*,int,void* ptr);

/*  malloc  */
#define malloc(size)  debug_malloc(__FILE__,__LINE__,(size))
/* free */
#define free(addr)    debug_free(__FILE__,__LINE__,(addr))


#endif

#endif


