public class Nodo
{
    private int id;
    private String nombre;
    private int edad;
    private Nodo siguiente;
    
    public void Nodo()
    {
        id = 0;
        nombre = "";
        edad = 0;
        siguiente = null;
    }
    
    public void setId(int n)
    {
        id  = n;
    }
    
    public int getId()
    {
        return id;
    }
    
    public void setNombre(String n)
    {
        nombre = n;
    }
    
    public String getNombre()
    {
        return nombre;
    }
    
    public void setEdad(int n)
    {
        edad = n;
    }
    
    public int getEdad()
    {
        return edad;
    }
    
    public void setSiguiente(Nodo n)
    {
        siguiente = n;
    }
    
    public Nodo getSiguiente()
    {
        return siguiente;
    }
}