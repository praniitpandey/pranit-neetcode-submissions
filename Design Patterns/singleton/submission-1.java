static class Singleton {
    private static String value;
    private static Singleton instance;

    private Singleton() {
        this.value = "default";
    }

    public static synchronized Singleton getInstance() {
        if (Singleton.instance == null) {
            Singleton.instance = new Singleton();
        }
        return Singleton.instance;
    }

    public String getValue() {
        return Singleton.value;
    }

    public void setValue(String value) {
        Singleton.value = value;
    }
}
