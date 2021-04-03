package nori.sample.multithread;

import java.util.*;
import java.util.concurrent.*;

public class Example{
	private int count,amountThread;

	private ExecutorService threadPool;

	public Example(){
		this(2);// 少なくとも2つのスレッド数を用意する。
	}
	public Example(int amountThread){
		if(amountThread<=0)
			this.amountThread=amountThread;
		else
			this.amountThread=2;
		
		this.threadPool=Executors.newFixedThreadPool(this.amountThread);
	}

	public void Start(){
		for(int i=0;i<this.amountThread;i++)
			this.threadPool.execute(this::Plus);

		this.threadPool.shutdown();
	}

	private synchronized void Plus(){
		while(this.count<1000000){
			this.count++;
			System.out.println(this.count);
		}

	}
}
