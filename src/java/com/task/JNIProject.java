package com.task;

public class JNIProject {
	static {
		System.loadLibrary("JNIProject");	// Load native library at runtime
											// hello.dll (Windows) or libhello.so (Unixes)
	}
	
	private native int initialize();
	private native int sum(int a, int b);
	private native int difference(int a, int b);
	private native int multiply(int a, int b);
	private native int divide(int a, int b);

	public static void main(String [] args) {
		int a = 3;
		int b = 2;
		JNIProject jniProject = new JNIProject();
		jniProject.initialize();
		System.out.println(a + " + " + b + " = " + jniProject.sum(a, b));
		System.out.println(a + " - " + b + " = " + jniProject.difference(a, b));
		System.out.println(a + "*" + b + " = " + jniProject.multiply(a, b));
		System.out.println(a + "/" + b + " = " + jniProject.divide(a, b));
	}
}