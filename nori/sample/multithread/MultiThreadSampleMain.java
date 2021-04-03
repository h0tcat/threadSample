package nori.sample.multithread;

public class MultiThreadSampleMain{

	public static void main(String[] args){
		if(args.length!=1){
			System.out.println("Usage: MultiThreadSampleMain N");
			System.exit(-1);
		}else{
			int amountThread=Integer.parseInt(args[0]);
			Example sampleProgram=new Example(amountThread);

			sampleProgram.Start();
		}
	}
}
