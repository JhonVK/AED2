import java.util.HashMap;

import classes.Person;

public class App {
    public static void main(String[] args) throws Exception {
        Person joao= new Person("joão", "30");
        HashMap<Person, String> h1= new HashMap<Person, String>();

        h1.put(joao, "pessoa 1");

        for (Person key : h1.keySet()) {
            System.out.println("Chave: " + key + ", Valor: " + h1.get(key));
        }
    }
}
