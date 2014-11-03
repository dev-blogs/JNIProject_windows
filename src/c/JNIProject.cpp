#include <windows.h>
#include "com_task_JNIProject.h"

HINSTANCE h;
int (* psum) (int, int);
int (* pdifference) (int, int);
int (* pmultiply) (int, int);
int (* pdivide) (int, int);

JNIEXPORT jint JNICALL Java_com_task_JNIProject_initialize(JNIEnv *env, jobject thisObj)
{
	h = LoadLibrary("C:\\practice\\JNI\\JNIProject\\build_c\\MathExpressions.dll");
	if (!h)
	{
		printf("%d Error - can't find library MathExpressions.dll\n", h);
		return 1;
	}
	psum=(int (*)(int, int)) GetProcAddress(h, "sum");
	pdifference=(int (*)(int, int)) GetProcAddress(h, "difference");
	pmultiply=(int (*)(int, int)) GetProcAddress(h, "multiply");
	pdivide=(int (*)(int, int)) GetProcAddress(h, "divide");
	if (!psum)
	{
		printf("Error psum\n");
		return 2;
	}
	if (!pdifference)
	{
		printf("Error pdifference\n");
		return 2;
	}
	if (!pmultiply)
	{
		printf("Error pmultiply\n");
		return 2;
	}
	if (!pdivide)
	{
		printf("Error pdivide\n");
		return 2;
	}
}

JNIEXPORT jint JNICALL Java_com_task_JNIProject_sum(JNIEnv *env, jobject thisObj, jint a, jint b)
{	
	return psum(a, b);
}

JNIEXPORT jint JNICALL Java_com_task_JNIProject_difference(JNIEnv *env, jobject thisObj, jint a, jint b)
{
	return pdifference(a, b);
}

JNIEXPORT jint JNICALL Java_com_task_JNIProject_multiply(JNIEnv *env, jobject thisObj, jint a, jint b)
{
	return pmultiply(a, b);
}

JNIEXPORT jint JNICALL Java_com_task_JNIProject_divide(JNIEnv *env, jobject thisObj, jint a, jint b)
{
	return pdivide(a, b);
}