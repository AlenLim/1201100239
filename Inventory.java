//enables Swing, Table and AWT
import javax.swing.*;
import javax.swing.table.*;
import java.awt.*;

//Inventory class uses Jtable provided by Swing to create specify table that provides two functions which is viewData and addData.
//Inventory class uses DefaultTableModel provided by Table to create specify table model for specify table.
public class Inventory{

	JFrame frame1 = new JFrame();

	Font f1 = new Font("Times New Roman",Font.BOLD,48);
	Font f2 = new Font("Times New Roman",Font.PLAIN,32);

	DefaultTableModel m1 = new DefaultTableModel();
	JTable t1 = new JTable(m1);
	JTableHeader th1 = t1.getTableHeader();
	JScrollPane sp1 = new JScrollPane(t1);

	Inventory(){

		m1.addColumn("MedicineCode");
		m1.addColumn("MedicineName");
		m1.addColumn("Quantity");
	   	m1.addColumn("Price");
	   
		t1.setPreferredSize(new Dimension(1400,14000));
		t1.setRowHeight(50);
		th1.setFont(f1);
		t1.setFont(f2);
	
		th1.setBackground(Color.green);
		t1.setBackground(Color.gray);

		frame1.setTitle("Inventory");
		frame1.setSize(1400, 700);
		frame1.setLocationRelativeTo(null); 
		frame1.setVisible(false);
	
		frame1.add(sp1);

	}

//viewData function used to set visibility of specify frame to visible.
	public void viewData(){
		
		frame1.setVisible(true);

	}

//addData function used to add row of specify data into specify table.
	public void addData(String MedicineCode,String MedicineName,String Quantity,String Price){

		m1.addRow(new Object[]{MedicineCode,MedicineName,Quantity,Price});

	}

}