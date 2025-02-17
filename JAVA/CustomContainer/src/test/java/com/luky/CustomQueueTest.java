package com.luky;

import com.luky.CustomQueue.Queue;

import com.luky.CustomQueue.CustomStack;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

public class CustomQueueTest {

	private com.luky.CustomQueue.Queue<String> queue_init (String[] data)  {
		com.luky.CustomQueue.Queue<String> queue = new CustomStack<>();
		for (int i = 0; i < data.length; i ++)  {
			queue.push(data[i]);	
		}

		return queue;
	}
	private String[][] getTestCases ()  {
		String[][] testCases = {
			{"Hello", "World", "Vegetable", "terrible"},
			{"ticket"},
			{},
		};

		return testCases;
	}
	private void print(Queue<String> queue)  {
			System.out.printf("Queue.toString() = %s%n",queue.toString());

	}
	public void testPush ()  {
		String[][] testCases = this.getTestCases();

		System.out.printf("Starting test TestCustomQueue.push()%n");
		for (int i = 0; i < testCases.length;i ++)  {
			String[] testCase = testCases[i];
			com.luky.CustomQueue.Queue<String> queue = this.queue_init(testCase);
			System.out.printf("Loppp %d: Queue.toString() = %s%n", i, queue.toString());
		}
	}
	public void testPop ()  {
		String[][] testCases = this.getTestCases();

		System.out.printf("Starting test CustomQueue.pop()%n");
		for (int i = 0; i < testCases.length; i ++)  {
			String[] testCase = testCases[i];
			com.luky.CustomQueue.Queue<String> queue = this.queue_init(testCase);

			for (int j = 0; j < 3; j ++)  {
				queue.pop();
			}
			this.print(queue);
		}
	}
}
