//enables File Handling and Swing
import java.io.*;
import javax.swing.*;

//class FileHandling provides three functions which are addLine, deleteLine and viewTable that uses functions provided by class Inventory.
public class FileHandling extends Inventory{

//addLine function uses FileWriter provided by File Handling to write specify data into specify text file.
//addLine function uses JOptionPane provided by Swing to show specify message.
	public void addLine(int Choice,String MedicineCode,String MedicineName,String Quantity,String Price) throws IOException{

		FileWriter la1 = new FileWriter("TraditionalHerbals.txt",true);
		FileWriter la2 = new FileWriter("ModernMedicines.txt",true);
		BufferedWriter a1 = new BufferedWriter(la1);
		BufferedWriter a2 = new BufferedWriter(la2);

			if(Choice == 1){

				a1.write(MedicineCode + "," + MedicineName + "," + Quantity + "," + Price); 
		   		a1.newLine();
				a1.close();

				JOptionPane.showMessageDialog(null,"Item KeyIn: Added.","Message",JOptionPane.PLAIN_MESSAGE);

			}

			else if(Choice == 2){

				a2.write(MedicineCode + "," + MedicineName + "," + Quantity + "," + Price); 
		   		a2.newLine();
				a2.close();

				JOptionPane.showMessageDialog(null,"Item KeyIn: Added.","Message",JOptionPane.PLAIN_MESSAGE);

			}

	}

//deleteLine function uses FileReader and FileWriter provided by File Handling to read specify data from specify text file then write them into another specify text file for replacing original file as an update.
//deleteLine function uses JOptionPane provided by Swing to show specify message.
	public void deleteLine(int Choice,String MedicineCode,String MedicineName,String Quantity,String Price) throws IOException{

		File file1 = new File("TraditionalHerbals.txt");
		File file2 = new File("ModernMedicines.txt");
        	File tempFile1 = new File("newTraditionalHerbals.txt");
        	File tempFile2 = new File("newModernMedicines.txt");
		FileReader ld1 = new FileReader(file1);
		FileReader ld2 = new FileReader(file2);
		FileWriter ld3 = new FileWriter(tempFile1,true);
		FileWriter ld4 = new FileWriter(tempFile2,true);
		BufferedReader d1 = new BufferedReader(ld1);
		BufferedReader d2 = new BufferedReader(ld2);
		BufferedWriter d3 = new BufferedWriter(ld3);
		BufferedWriter d4 = new BufferedWriter(ld4);
			
			if(Choice == 1){

				String lineToRemove = MedicineCode + "," + MedicineName + "," + Quantity + "," + Price;
				String line;

				while((line = d1.readLine()) != null){

					if(!line.equals(lineToRemove)){

            				d3.write(line);
						d3.newLine();

					}

					else{

						JOptionPane.showMessageDialog(null,"Item KeyIn: Deleted.","Message",JOptionPane.PLAIN_MESSAGE);

					}

				}
								
				d3.close();
				d1.close();
				file1.delete();
				tempFile1.renameTo(file1);

			}

			else if(Choice == 2){
		
				String lineToRemove = MedicineCode + "," + MedicineName + "," + Quantity + "," + Price;
				String line;

				while((line = d2.readLine()) != null){

					if(!line.equals(lineToRemove)){

            				d4.write(line);
						d4.newLine();

					}

					else{

						JOptionPane.showMessageDialog(null,"Item KeyIn: Deleted.","Message",JOptionPane.PLAIN_MESSAGE);

					}

				}

				d4.close();
				d2.close();
				file2.delete();
				tempFile2.renameTo(file2);

			}

	}

//viewTable function uses FileReader provided by File Handling to read specify data from specify text file then add them into specify table of class Inventory by using add function provided in that class and display specify table of class Inventory by using visible function provided in that class.
	public void viewTable(int Choice) throws IOException{

		FileReader tv1 = new FileReader("TraditionalHerbals.txt");
		FileReader tv2 = new FileReader("ModernMedicines.txt");
		BufferedReader v1 = new BufferedReader(tv1);
		BufferedReader v2 = new BufferedReader(tv2);

			if(Choice == 1){

				Inventory inventory = new Inventory();

				String line;

				while((line = v1.readLine()) != null){

					String[] data = line.split(",");
					inventory.addData(data[0],data[1],data[2],data[3]);

				}

				v1.close();
				inventory.viewData();

			}

			else if(Choice == 2){

				Inventory inventory = new Inventory();

				String line;

				while((line = v2.readLine()) != null){

					String[] data = line.split(",");
					inventory.addData(data[0],data[1],data[2],data[3]);

				}

				v2.close();
				inventory.viewData();

			}

	}

}