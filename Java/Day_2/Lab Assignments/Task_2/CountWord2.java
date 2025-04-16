
 class CountWord2{
public static void main(String[] args){
	    String sentence = args[0];
        String word = args[1];
        int count = 0;
        int index = 0;

        String[] words = sentence.split("");
		
        for (int i =0 ; i< words.length;i++) {
            if (words[i].equals(word)) {
                count++;
            }
        }

        System.out.println("The word \"" + word + "\" -----> " + count + " times.");
}
}