import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class Data {

    public String getDateTime() {
        DateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");
        Date date = new Date();
        return dateFormat.format(date);
    }

    private int dia;
    private int mes;
    private int ano;
    
    public void setData(int d, int m, int a)
    {
        dia = d;
        mes = m;
        ano = a;
    }

    public String getData()
    {
        return String.valueOf(dia) + "/" + String.valueOf(mes) + "/" + String.valueOf(ano);
    }
}
