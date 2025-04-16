
 class CountWord{
public static void main(String[] args){
	    String sentence = args[0];
        String word = args[1];
        int count = 0;
        int index = 0;

        while ((index = sentence.indexOf(word, index)) != -1) {
            count++;
            index += word.length();
        }

        System.out.println("The word \"" + word + "\" -----> " + count + " times.");
}
}