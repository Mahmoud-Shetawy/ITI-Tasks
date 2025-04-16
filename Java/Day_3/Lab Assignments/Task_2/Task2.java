 class Task2 {
    public static void main(String[] args) {
        double a = 4, b = 4, c = 1;

        double delta = calDelta(a, b, c);
        if (delta > 0) {
            double root1 = calRoot(a, b, delta, true);
            double root2 = calRoot(a, b, delta, false);
			
            System.out.println("Root 1: " + root1);
            System.out.println("Root 2: " + root2);
			
        }


		else if (delta == 0) {
            double root = calRoot(a, b, delta, true);
            System.out.println("One Root: " + root);
        } 
		
		
		
		
		else {
            System.out.println("No real roots.");
        }
    }

    public static double calDelta(double a, double b, double c) {
        return (b * b) - (4 * a * c);
    }

    public static double calRoot(double a, double b, double delta, boolean isPositive) {
        double sqrtDelta = Math.sqrt(delta);
        return isPositive
                ? (-b + sqrtDelta) / (2 * a) 
                : (-b - sqrtDelta) / (2 * a); 
    }
}
