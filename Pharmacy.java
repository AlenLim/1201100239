//enables File Handling, Swing, AWT and Event
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

//Pharmacy class uses JPanel provided by Swing to create specify layout that provides main function.
//Pharmacy class uses JButton provided by Swing to create specify button that uses function provided by class FileHandling.
//Pharmacy class uses addActionListener provided by Event to create specify action event for specify button.
public class Pharmacy extends FileHandling{

	FileHandling filehandling = new FileHandling();
	   
	JFrame frame = new JFrame();

	JPanel p1 = new JPanel(new FlowLayout(FlowLayout.CENTER,0,40));
	JPanel p2 = new JPanel(new GridLayout(2,1,0,20));
	JPanel p3 = new JPanel(new GridLayout(4,1,0,0));
	JPanel p3a = new JPanel(new FlowLayout(FlowLayout.LEFT,90,40));
	JPanel p3b = new JPanel(new FlowLayout(FlowLayout.LEFT,90,40));
	JPanel p3c = new JPanel(new FlowLayout(FlowLayout.LEFT,90,40));
	JPanel p3d = new JPanel(new FlowLayout(FlowLayout.LEFT,90,40));
	JPanel p4 = new JPanel(new GridLayout());
	JPanel p5 = new JPanel(new FlowLayout(FlowLayout.CENTER,160,40));
	
	Box eb1 = new Box(BoxLayout.X_AXIS);
	
	Font f1 = new Font("Ariel",Font.BOLD,72);
	Font f2 = new Font("Times New Roman",Font.BOLD,24);
  	Font f3 = new Font("Times New Roman",Font.PLAIN,24);

   	JLabel l1 = new JLabel("Pharmacy Inventory Management System");
   	JLabel l2 = new JLabel("Medicine Code: ");
   	JLabel l3 = new JLabel("Medicine Name: ");
   	JLabel l4 = new JLabel("Quantity: ");
   	JLabel l5 = new JLabel("Price: ");
	
   	JTextField tf1 = new JTextField("\t------ (code_number) ------");
   	JTextField tf2 = new JTextField("\t------ (name) ------");
   	JTextField tf3 = new JTextField("\t------ (amount) ------");
   	JTextField tf4 = new JTextField("\t------ (total_cost) ------");
	
	JButton b1 = new JButton("Add");
   	JButton b2 = new JButton("Delete");
   	JButton b3 = new JButton("View");
	   
   	ButtonGroup bg1 = new ButtonGroup();
   	JRadioButton rb1 = new JRadioButton("Herbals",true);
   	JRadioButton rb2 = new JRadioButton("Pills",false);  

   	Pharmacy(){
	   	   	
		l1.setFont(f1);
	
		p1.setBackground(Color.green);
	
		p1.add(l1);
	
		rb1.setPreferredSize(new Dimension(250,0));
		rb1.setFont(f2);
		rb2.setPreferredSize(new Dimension(250,0));
		rb2.setFont(f2);

		rb1.setBackground(Color.lightGray);
		rb2.setBackground(Color.lightGray);

		rb1.setActionCommand("Herbals");
		rb2.setActionCommand("Pills");

		bg1.add(rb1);
		bg1.add(rb2);
	
		p2.add(rb1);
		p2.add(rb2);

		l2.setFont(f2);
		l3.setFont(f2);
		l4.setFont(f2);
		l5.setFont(f2);
		   
		tf1.setPreferredSize(new Dimension(800,50));
		tf1.setFont(f3);
		tf2.setPreferredSize(new Dimension(800,50));
		tf2.setFont(f3);
		tf3.setPreferredSize(new Dimension(800,50));
		tf3.setFont(f3);
		tf4.setPreferredSize(new Dimension(800,50));
		tf4.setFont(f3);

		p3a.setBackground(Color.white);
		p3b.setBackground(Color.white);
		p3c.setBackground(Color.white);
		p3d.setBackground(Color.white);

		p3.setBackground(Color.white);

		p3a.add(l2);
		p3a.add(tf1);
		p3b.add(l3);
		p3b.add(tf2);
		p3c.add(l4);
		p3c.add(tf3);
		p3d.add(l5);
		p3d.add(tf4);
		
		p3.add(p3a);
		p3.add(p3b);
		p3.add(p3c);
		p3.add(p3d);

		p4.add(Box.createRigidArea(new Dimension(250,0)));
		
		b1.setPreferredSize(new Dimension(125,50));
		b1.setFont(f2);
		b2.setPreferredSize(new Dimension(125,50));
		b2.setFont(f2);
		b3.setPreferredSize(new Dimension(125,50));
		b3.setFont(f2);

		b1.setBackground(Color.lightGray);
		b2.setBackground(Color.lightGray);
		b3.setBackground(Color.lightGray);

		p5.setBackground(Color.darkGray);
	
		p5.add(b1);
		p5.add(b2);
		p5.add(b3);
	
		frame.setTitle("Pharmacy");
		frame.setSize(1800, 900);
		frame.setLayout(new BorderLayout(20,20));
		frame.setLocationRelativeTo(null); 
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	
		frame.add(p1,"North");
		frame.add(p2,"West");
		frame.add(p3,"Center");
		frame.add(p4,"East");
		frame.add(p5,"South");

			b1.addActionListener(new ActionListener(){

   				public void actionPerformed(ActionEvent ae){

					try{

						if(!(tf1.getText().trim().equals("")) && !(tf2.getText().trim().equals("")) && !(tf3.getText().trim().equals("")) && !(tf4.getText().trim().equals(""))){
							
							if(bg1.getSelection().getActionCommand() == "Herbals"){

								filehandling.addLine(1,tf1.getText(),tf2.getText(),tf3.getText(),tf4.getText());

							}

							else if(bg1.getSelection().getActionCommand() == "Pills"){

								filehandling.addLine(2,tf1.getText(),tf2.getText(),tf3.getText(),tf4.getText());

							}

						}

						else{

							JOptionPane.showMessageDialog(null,"It is empty. Please make sure all data items keyin.","Message",JOptionPane.PLAIN_MESSAGE);

						}

					}

					catch(FileNotFoundException fe){

						System.out.println("Error: FileNotFound error");
						fe.printStackTrace();

					}

					catch(IOException ioe){

						System.out.println("Error: WritingFile error");
						ioe.printStackTrace();

					}

				}

			});

			b2.addActionListener(new ActionListener(){

   				public void actionPerformed(ActionEvent ae){

					try{

						if(!(tf1.getText().trim().equals("")) && !(tf2.getText().trim().equals("")) && !(tf3.getText().trim().equals("")) && !(tf4.getText().trim().equals(""))){

							if(bg1.getSelection().getActionCommand() == "Herbals"){

								filehandling.deleteLine(1,tf1.getText(),tf2.getText(),tf3.getText(),tf4.getText());

							}

							else if(bg1.getSelection().getActionCommand() == "Pills"){

								filehandling.deleteLine(2,tf1.getText(),tf2.getText(),tf3.getText(),tf4.getText());

							}

						}

						else{

							JOptionPane.showMessageDialog(null,"It is empty. Please make sure all data items keyin.","Message",JOptionPane.PLAIN_MESSAGE);

						}

					}

					catch(FileNotFoundException fe){

						System.out.println("Error: FileNotFound error");
						fe.printStackTrace();

					}

					catch(IOException ioe){

						System.out.println("Error: Reading/WritingFile error");
						ioe.printStackTrace();

					}

				}

			});

			b3.addActionListener(new ActionListener(){

   				public void actionPerformed(ActionEvent ae){

					try{

						if(bg1.getSelection().getActionCommand() == "Herbals"){

							filehandling.viewTable(1);

						}

						else if(bg1.getSelection().getActionCommand() == "Pills"){

							filehandling.viewTable(2);

						}

					}

					catch(FileNotFoundException fe){

						System.out.println("Error: FileNotFound error");
						fe.printStackTrace();

					}

					catch(IOException ioe){

						System.out.println("Error: ReadingFile error");
						ioe.printStackTrace();

					}

				}

			});

	}

//main function used to call new constructor of class Pharmacy.
	public static void main(String[] args){

		new Pharmacy();

   	}

}