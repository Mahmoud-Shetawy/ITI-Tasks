import java.util.function.Function;

 class TemperatureConvert implements Function<Float, Float> {
    @Override
    public Float apply(Float t) {
        return t * 9 / 5 + 32;
    }
}

 class Task1 {
    public static void main(String[] args) {
        float x = 10;
        System.out.println("Temp is = " + x + "C or " + new TemperatureConvert().apply(x) + "F");
    }
}
