import java.util.function.Function;

public class Main {
    public static void main(String[] args) {
        float celsius = 24.0f;

        Function<Float, Float> celsiusToFahrenheit = new Function<Float, Float>() {
            @Override
            public Float apply(Float celsius) {
                return (celsius * 9 / 5) + 32;
            }
        };

        float fahrenheit = celsiusToFahrenheit.apply(celsius);

        System.out.println(celsius + "°C is " + fahrenheit + "°F");
    }
}