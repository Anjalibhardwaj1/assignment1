
public class Rectangle extends PrintableObject implements Shape {

	double side1;
	double side2;
	
	//default constructor
	public Rectangle() {
		this.side1 = 1;
		this.side2 = 2;
	}
	
	//parameterized constructor
	public Rectangle(double side1, double side2) {
		this.side1 = side1;
		this.side2 = side2;
	}
	
	//copy constructor
	public Rectangle(Rectangle r) {
		this.side1 = r.side1;
		this.side2 = r.side2;
	}
	
	public String toString() {
		return super.toString() + ", " + this.side1 + " " + this.side2;
	}
	
	public static Rectangle parse(String s) {
		String[] sides = s.split(",");
		double side1 = Double.valueOf(sides[1]);
		double side2 = Double.valueOf(sides[2]);
		return new Rectangle(side1, side2);
	}
	
	public double getSide1() {
		return side1;
	}

	public void setSide1(double side1) {
		this.side1 = side1;
	}

	public double getSide2() {
		return side2;
	}

	public void setSide2(double side2) {
		this.side2 = side2;
	}
	
	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return (2*this.side1) + (2*this.side2);
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		return this.side1*this.side2;
	}

}
