import java.util.LinkedList;

public class HashTable {
    private final int tamanho=7;
    LinkedList<Integer> []lista;


    @SuppressWarnings("unchecked")
    public HashTable(){
        lista= new LinkedList[tamanho];
        for(int i=0; i<7; i++){
            lista[i]= new LinkedList<>();
        }
    }

    public int hashFunction(int key){
        return key%tamanho;
    }
    public void insert(int key){ 
        int hashIndex = hashFunction(key); 
        lista[hashIndex].add(key); 
    }
    public boolean search(int key){ 
        int hashIndex = hashFunction(key); 
        return lista[hashIndex].contains(key); 
    }
    public void delete(int key){
        int hashIndex = hashFunction(key);
        lista[hashIndex].remove((Integer) key); 
    }
    public void display(){ 
        for(int i = 0; i < tamanho; i++){ 
            System.out.print("Index " + i + ":"); 
                for(int key : lista[i]){ 
                    System.out.print(" -> " + key); 
                } 
                System.out.println(); 
            }
    }

}
