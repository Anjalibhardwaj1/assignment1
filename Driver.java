import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;


public class main {

	public static void main(String[] args) throws IOException {
		
		//arraylist to store shapes in an array
		ArrayList<Shape> shape_list = new ArrayList<Shape>();
		String name;
		Scanner k = new Scanner(System.in);
		System.out.println("Please provide file path: ");
		name = k.nextLine();
		
		//try-with-resources file
		try(FileInputStream f = new FileInputStream(name)){
			Scanner sc = new Scanner(f);
			while (sc.hasNextLine()) {
				String data = sc.nextLine();
				String[] data1 = data.split(",");
				
				//parse and store the shapes in an array of Shapes
				if (data1[0].toLowerCase().equals("rectangle") && (data1.length == 3)) {
					shape_list.add(Rectangle.parse(data));
				} else if (data1[0].toLowerCase().equals("circle") && (data1.length == 2)) {
					shape_list.add(Circle.parse(data));
				} else {
					System.out.println("Incorrect data. Shape " + data1[0] + " cannot be parsed");
				}
			}
			//sorting by name
			Collections.sort(shape_list, new Comparator<Shape>() {
					@Override
					public int compare(Shape s1, Shape s2) {
						return s1.getName().compareTo(s2.getName());
					}
			});
			
			//printing elements by name sort
			System.out.println("based on name sorting.....");

			Printable.print(java.util.Arrays.copyOf(shape_list.toArray(), shape_list.size(), Printable[].class));
			
			//sorting by area
			Collections.sort(shape_list, new Comparator<Shape>() {
					@Override
					public int compare(Shape s1, Shape s2) {
						return Double.compare(s1.getArea(), s2.getArea());
					}
			});
			
			//printing elements by area sort
			System.out.println("based on area sorting.....");
			
			
			Printable.print(java.util.Arrays.copyOf(shape_list.toArray(), shape_list.size(), Printable[].class));
			
			sc.close();
		} catch (FileNotFoundException e) {
			System.out.println("An error occured.");
		}
		


	}
	
}
