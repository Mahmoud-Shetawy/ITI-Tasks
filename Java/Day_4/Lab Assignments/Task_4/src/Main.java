 interface Complex<T> {
    T getReal();
    T getImaginary();
}

 class DoubleComplex implements Complex<Double> {
      final Double imaginary;
      final Double real;

    public DoubleComplex(Double real, Double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    @Override
    public Double getReal() {
        return real;
    }

    @Override
    public Double getImaginary() {
        return imaginary;
    }

    @Override
    public String toString() {
        return real + " + " + imaginary + "i";
    }
}

public class Main {
    public static void main(String[] args) {
        DoubleComplex z1 = new DoubleComplex(3.0, 2.0);
        DoubleComplex z2 = new DoubleComplex(1.0, 4.0);

        System.out.println("z1: " + z1);
        System.out.println("z2: " + z2);
    }
}
