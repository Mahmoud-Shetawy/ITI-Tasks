 class IPCutter {
    String cmdLine;

    public IPCutter(String cmdLine_) {
        cmdLine = cmdLine_;
    }

    public int[] doIPSplit() {
        String[] parts = cmdLine.split("\\.");
        
		
		int[] result = new int[parts.length];
		
		
        for (int i = 0; i < parts.length; i++) {
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }
}

public class Task1 {
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