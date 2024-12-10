public static void main(String[] args) {
    HashTable hashTable = new HashTable();
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(22);
    hashTable.insert(30);
    hashTable.insert(45);
    hashTable.insert(50);
    hashTable.insert(18);

    hashTable.display();

    System.out.println("Search 15: " + hashTable.search(15));
    System.out.println("Search 22: " + hashTable.search(22));
    System.out.println("Search 40: " + hashTable.search(40));

    hashTable.delete(15);
    hashTable.delete(22);
    hashTable.delete(45);

    hashTable.display();
    }

