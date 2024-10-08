public class Abc {

    public String getString() {
        return string;
    }

    public int getValue() {
        return value;
    }

    private String string;
    private int value;

    public Abc(String string, int value) {
        this.string = string;
        this.value = value;
    }

    @Override
    public boolean equals(Object object) {
        if (object == this) {
            return true;
        }
        if (!(object instanceof Abc)) {
            return false;
        }
        Abc abc = (Abc) object;
        return string.equals(abc.getString()) && value == abc.getValue();
    }

}