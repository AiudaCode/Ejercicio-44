public class ListaSimple
{
    private Nodo cabeza;
    
    public ListaSimple()
    {
        cabeza = null;
    }
    
    public void setCabeza(Nodo n)
    {
        cabeza = n;
    }
    
    public Nodo getCabeza()
    {
        return cabeza;
    }
    
    public Nodo ultimo()
    {
        Nodo temp = cabeza;
        while(temp != null)
        {
            if(temp.getSiguiente() == null)
            {
                break;
            }
            else
            {
                temp = temp.getSiguiente();
            }
        }
        return temp;
    }
    
    
    public int contarNodos()
    {
        Nodo temp = cabeza;
        int contador = 0;
        while(temp != null)
        {
            contador++;
            temp = temp.getSiguiente();
        }
        return contador;
    }
    
    public void agregarFinal(Nodo n)
    {
        if(cabeza == null)
        {
            setCabeza(n);
        }
        else
        {
            ultimo().setSiguiente(n);
        }
    }
    
    public void agregarEntreNodos(Nodo nd, Nodo nuevo)
    {
        //donde nd es el Nodo anterior (A) y nuevo es el NUEVO NODO
        //Se necesita dos nodos A & B por ejemplo
        //A debe apuntar al nuevo nodo auxiliar y el nodo auxiliar
        //apuntara al nodo B.
        nuevo.setSiguiente(nd.getSiguiente());
        //el siguiente de nuevo sera el siguiente de A (B). 
        nd.setSiguiente(nuevo);
        //el NODO nd (A) apunta al nodo nuevo.
    }
    
    public void agregarInicio(Nodo n)
    {
        n.setSiguiente(cabeza);
        setCabeza(n);
    }
    
    Nodo buscarId(int c)
    {
        Nodo temp = cabeza;
        while(temp != null)
        {
            if(temp.getId() == c)
            {
                break;
            }
            else
            {
                temp = temp.getSiguiente();
            }
        }
        return temp;
    }
    
    Nodo buscarNombre(String n)
    {
        Nodo temp = cabeza;
        while(temp != null)
        {
            if(temp.getNombre().equals(n))
            {
                break;
            }
            else
            {
                temp = temp.getSiguiente();
            }
        }
        return temp;
    }
    
    public void eliminar(Nodo nd){
        Nodo anterior;
        // si el nodo a eliminar en la lista es el primero entonces
        if (nd == cabeza)
        { 
            cabeza = cabeza.getSiguiente();
        }
        else
        {
            // se busca el nodo anterior al que se quiere eliminar (nd)
            anterior = cabeza;
            while (anterior.getSiguiente() != nd)
            {
                anterior = anterior.getSiguiente();
            }
            // el nodo anterior ahora apuntara al siguiente nodo de nd
            anterior.setSiguiente(nd.getSiguiente());
        }
        nd.setSiguiente(null);
    }
    
    public void limpiar()
    {
        while(cabeza != null)
        {
            eliminar(cabeza);
        }
    } 
}