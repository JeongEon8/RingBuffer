#pragma once

class CircularBuffer
{
	int bufsize;
	SensorRecord[] store;
	int numberOfEntries = 0;
	int front = 0, back = 0;
	CircularBuffer(int n) {
		bufsize = n;
		store = new SensorRecord[bufsize];
	} // CircularBuffer
	synchronized void put(SensorRecord rec)
		throws InterruptedException
	{
		if (numberOfEntries == bufsize)
			wait();
		store[back] = new SensorRecord(rec.sensorId, recback = back + 1;
		if (back == bufsize)
			back = 0;
		numberOfEntries = numberOfEntries + 1;
		notify();
	} // put
	synchronized SensorRecord get() throws InterruptedException
	{
		SensorRecord result = new SensorRecord(-1, -1);
		if (numberOfEntries == 0)
			wait();
		result = store[front];
		front = front + 1;
		if (front == bufsize)
			front = 0;
		numberOfEntries = numberOfEntries - 1;
		notify();
		return result;
	} // get
} // CircularBuffer