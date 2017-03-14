import javax.swing.JOptionPane;

public class Main
{
    public static void llenar(Nodo n, ListaSimple obj)
    {
        int id = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite identificación:"));
        n.setId(id);
        String nom = JOptionPane.showInputDialog(null, "Digite nombre:");
        n.setNombre(nom);
        int edad = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite edad:"));
        n.setEdad(edad);
    }
    
    public static void mostrar(Nodo n)
    {
        String datos = "";
        datos += String.valueOf("ID: " + n.getId()+ "\n" +
                                "Nombre: " + n.getNombre() + "\n" +
                                "Edad: " + n.getEdad());
        JOptionPane.showMessageDialog(null, "=========== INFORMACÓN DE LOS NODOS DE LA LISTA =========== \n"+ datos);
    }
    
    public static void listarTodos(Nodo n)
    {
        Nodo temp = n;
        while(temp != null)
        {
            mostrar(temp);
            temp = temp.getSiguiente();
        }
    }
    
    public static int menu()
    {
        int opcion = 0;
        do
        {
            opcion = Integer.parseInt(JOptionPane.showInputDialog("=========== SELECCIONE UNA OPCIÓN DEL MENÚ =========== \n" +
            "1. Agregar estudiante al final de la Lista \n" +
            "2. Agregar estudiante entre dos Nodos existentes\n" +
            "3. Agregar estudiante al principio de la lista\n" +
            "4. Buscar estudiante por ID o por Nombre\n" +
            "5. Mostrar nodos de la lista\n" +
            "6. Cantidad de nodos que hay en la lista\n" +
            "7. Eliminar nodo de la lista\n" + 
            "8. Eliminar toda la lista\n" +
            "9. Salir\n\n" +
            " Seleccione una opción del 1 al 9:"));
        }
        while(opcion < 1 || opcion > 9);
        return opcion;
    }
    
    public static void main(String[] args)
    {
        ListaSimple obj = new ListaSimple();
        int opcion, id;
        String nombre;
        Nodo aux;
        do
        {
            opcion = menu();
            switch(opcion) 
            {
                case 1:
                    aux = new Nodo();
                    llenar(aux, obj);
                    obj.agregarFinal(aux);
                    break;
                case 2:
                    id = Integer.parseInt(JOptionPane.showInputDialog("Digite ID del estudiante que quiere agregar: "));
                    Nodo nd = obj.buscarId(id);
                    if(nd != null)
                    {
                        aux = new Nodo();
                        llenar(aux, obj);
                        obj.agregarEntreNodos(nd, aux);
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null, "La ID NO se encuentra en la lista");
                    }
                    break;
                case 3:
                    aux = new Nodo();
                    llenar(aux, obj);
                    obj.agregarInicio(aux);
                    
                    if(obj.getCabeza() != null)
                    {
                        listarTodos(obj.getCabeza());
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null, "La Lista Está Vacía....");
                    }
                    break;
                case 4:
                    int opc;
                    do
                    {
                        opc = Integer.parseInt(JOptionPane.showInputDialog("Como desea realizar la busqueda:\n 1. ID\n 2. Nombre"));
                    }
                    while(opc < 1 || opc > 2);
                    if(opc == 1)
                    {
                        id = Integer.parseInt(JOptionPane.showInputDialog("Digite ID del estudiante a Buscar: "));
                        aux = obj.buscarId(id);
                        if(aux != null)
                        {
                            mostrar(aux);
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null, "La información del estudiante No se encuentra en la lista");
                        }
                    }
                    else
                    {
                        nombre = JOptionPane.showInputDialog("Digite Nombre del estudiante a Buscar: ");
                        aux = obj.buscarNombre(nombre);
                        if(aux != null)
                        {
                            mostrar(aux);
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null, "La información del estudiante No se encuentra en la lista");
                        }
                    }
                    break;
                case 5:
                    aux = obj.getCabeza();
                    if (aux != null)
                    {
                        listarTodos(aux);
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null, "No hay nodos en la lista.");
                    }
                    break;
                case 6:
                    JOptionPane.showMessageDialog(null, "Hay " + obj.contarNodos() + " nodos en la lista.");
                    break;
                case 7:
                    aux = obj.getCabeza();
                    if (aux != null)
                    {
                        obj.eliminar(aux);
                        JOptionPane.showMessageDialog(null, "Se elimino un nodo correctamente.");
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null, "No hay nodo en la lista.");
                    }
                    break;
                case 8:
                    obj.limpiar();
                    JOptionPane.showMessageDialog(null, "La lista se ha eliminado.");
                    break;
                default:
                    break;
            }
        }
        while(opcion != 9);
    }
}