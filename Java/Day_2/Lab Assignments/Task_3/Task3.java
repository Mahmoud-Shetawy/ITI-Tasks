class ArrAlg {
    public int max(int[] array) {
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }

    public int min(int[] array) {
        int min = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] < min) {
                min = array[i];
            }
        }
        return min;
    }
}
 class Task3 {
    public static void main(String[] args) {
        int[] myArray = {23, 92, 56, 39, 93, 90, 123, 152, 70, 60, 90, 5};
        ArrAlg m = new ArrAlg();

        long startTime = System.nanoTime();
		
        int max = m.max(myArray);
        int min = m.min(myArray);
		
        long endTime = System.nanoTime();

        System.out.println("Maximum value in the array is: " + max);
        System.out.println("Minimum value in the array is: " + min);
        System.out.println("Running time for finding min and max: " + (endTime - startTime) + " nanoseconds");
    }
}