import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/*
 * Question: Despite the fact that all shapes are either Rectangle or Circle, you cannot pass
an a Shape[] array as Printable[] to the print method. Why?
Solution: Use the following solution:
Shape[] shapes = ...
Printable.print(java.util.Arrays.copyOf(shapes, shapes.length, Printable[].cl*/

public class Driver {

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
				if (data1[0].equals("Rectangle")) {
					//System.out.println(data1[0]);
					shape_list.add(Rectangle.parse(data));
				} else {
					shape_list.add(Circle.parse(data));
				}
			}
			//sorting by name
			Collections.sort(shape_list, new Comparator<Shape>() {
				//??do we add this///What is an anonymous class? 
//				class CompareShapes implements Comparator<Shape>{
					@Override
					public int compare(Shape s1, Shape s2) {
						return s1.getName().compareTo(s2.getName());
					}
//				}
			});
			
			//printing elements by name sort
			//array list converted to array
			System.out.println("based on name sorting.....");
			
			
			
			//**use the vararg for the argument type and use java "foreach" to loop through the elements 
//			Printable.print(java.util.Arrays.copyOf(shape_list.toArray(), shape_list.size(), Printable[].class));
			Printable.print(java.util.Arrays.copyOf(shape_list.toArray(), shape_list.size(), Printable[].class));

			
			//sorting by area
			//do we also have to compare the names? 
			Collections.sort(shape_list, new Comparator<Shape>() {
					@Override
					public int compare(Shape s1, Shape s2) {
						return Double.compare(s1.getArea(), s2.getArea());
					}
			});
			
			//printing elements by area sort
			System.out.println("based on area sorting.....");
			
			
			//**use the vararg for the argument type and use java "foreach" to loop through the elements 
			Printable.print(java.util.Arrays.copyOf(shape_list.toArray(), shape_list.size(), Printable[].class));
			
			sc.close();
		} catch (FileNotFoundException e) {
			System.out.println("An error occured.");
		}
		


	}
	
}

