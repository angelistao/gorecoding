



public class App {
    public static void main(String[] args) {
        ListArrayOfInteger_V2 lista = new ListArrayOfInteger();
        lista.add(2);
        lista.add(4);
        lista.add(6);
        lista.add(8);
        lista.add(0,0);
        lista.add(5,10);
        lista.add(3,5);
        
        System.out.println(lista);
       
        lista.remove(8);
        lista.remove(0);
        lista.remove(10);
        
        System.out.println("Apos remocao de 0,8,10: " +lista);
        
        System.out.println("Elemento armazenado na "
                + "primeira posicao da lista: " +lista.get(0));

    }
}
