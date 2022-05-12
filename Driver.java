import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Driver {

	public static void main(String[] args) {
		
		ArrayList<Shape> shape_list = new ArrayList<Shape>();
		
		try {
			File f = new File("C:/Users/r_mobeen/Documents/assignment1/shapes.txt");
			Scanner sc = new Scanner(f);
			while (sc.hasNextLine()) {
				String data = sc.nextLine();
				String[] data1 = data.split(",");
				//for (String i : data1) {
				//	System.out.println(i);
				//}
				
				//checks if shape is rectangle or circle
				if (data1[0].equals("Rectangle")) {
					//System.out.println(data1[0]);
					shape_list.add(Rectangle.parse(data));
				} else {
					shape_list.add(Circle.parse(data));
				}
			}
			sc.close();
		} catch (FileNotFoundException e) {
			System.out.println("An error occured");
		}
		
		//sorting by name
		Collections.sort(shape_list, new Comparator<Shape>() {

			@Override
			public int compare(Shape s1, Shape s2) {
				return s1.getName().compareTo(s2.getName());
			}
		});
		
		//printing elements by name sort
		//array list converted to array
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

	}
	
}
