/**********************************************************************
 **********************************************************************
 *  File:    memDetector.h
 *  Description:
 *       Header file to other project which provide the Interface to 
 *       operator new & detete.
 *
 *  Author:  ewentzh
 *  Date:    2012-7-3
 *
 *  Change List:
 *      1.   2012-7-3  First Revion!!
 *
 **********************************************************************
 **********************************************************************
 * */


#ifndef __MEM_DETECTOR__INTERFACE_H__
#define __MEM_DETECTOR__INTERFACE_H__

#define USE_MEM_DETECTOR

#ifdef USE_MEM_DETECTOR
// malloc
//#include <new>
extern void* debug_malloc(const char*, int,int);
extern void  debug_free(const char*,int,void* ptr);

/*  malloc  */
#define malloc(size)  debug_malloc(__FILE__,__LINE__,(size))
/* free */
#define free(addr)    debug_free(__FILE__,__LINE__,(addr))


extern void* operator new(size_t,const char*,const char*,int);
extern void* operator new[](size_t,const char*,const char*,int);
extern void  operator delete(void* );
extern void  operator delete[](void*);

#define new new(__FILE__,__func__,__LINE__)
//#define delete delete (__FILE__,__func__,__LINE__)
//#define delete __log_delete(__FILE__), delete


#endif
#endif


