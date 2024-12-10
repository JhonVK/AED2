import java.util.HashMap;

import classes.Person;

public class App {
    public static void main(String[] args) throws Exception {
        Person joao= new Person("joão", 100);
        HashMap<String, Person> h1= new HashMap<String, Person>();

        h1.put("pessoa 1", joao);

        for (String key : h1.keySet()) {
            Person person = h1.get(key);
            System.out.println("Chave: " + key + ", Valor: " + person + ", HashCode: " + person.hashCode());
        }
    }
}
