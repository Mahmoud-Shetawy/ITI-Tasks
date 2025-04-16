import java.util.StringTokenizer;

 class IPCutter {
    String cmdLine;

    public IPCutter(String cmdLine_) {
        cmdLine = cmdLine_;
    }

    public int[] doIPSplit() {
        StringTokenizer tokenizer = new StringTokenizer(cmdLine, ".");
		
        int[] result = new int[tokenizer.countTokens()];
       
	   int i = 0;
        while (tokenizer.hasMoreTokens()) {
            result[i++] = Integer.parseInt(tokenizer.nextToken());
        }
        return result;
    }
}

public class Task1_2 {
    public static void main(String[] args) {
		
        String commandLine = args[0];
		
        IPCutter cut = new IPCutter(commandLine);
		
        System.out.println("The output of " + commandLine + " is");
		
        int[] out = cut.doIPSplit();
		
        for (int i = 0; i < out.length; i++) {
            System.out.println(out[i]);
        }
    }
}