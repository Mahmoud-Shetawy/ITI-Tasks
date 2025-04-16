
class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }
}

class ExceptionThrower {
    public void method1() throws CustomException {
        throw new CustomException("Exception thrown from method1");
    }

    public void method2() throws CustomException {
        throw new CustomException("Exception thrown from method2");
    }

    public void method3() throws CustomException {
        throw new CustomException("Exception thrown from method3");
    }
}

public class Main {
    public static void main(String[] args) {
        ExceptionThrower thrower = new ExceptionThrower();

        try {
            thrower.method1();
        } catch (CustomException e) {
            System.out.println("Caught exception: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed for method1");
        }

        try {
            thrower.method2();
        } catch (CustomException e) {
            System.out.println("Caught exception: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed for method2");
        }

        try {
            thrower.method3();
        } catch (CustomException e) {
            System.out.println("Caught exception: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed for method3");
        }
    }
}