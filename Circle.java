public class Circle extends PrintableObject implements Shape {

	double radius;
	
	//default constructor 
	public Circle() {
		this.radius = 1;
	}
	
	//parameterized constructor
	public Circle(double radius) {
		this.radius = radius;
	}
	
	//copy constructor
	public Circle(Circle c) {
		this.radius = c.radius;
	}
	
	public String toString() {
		return super.toString() + ", " + this.radius;
	}
	
	public static Circle parse(String s) {
		String[] sides = s.split(",");
		double rad = Double.valueOf(sides[1]);
		return new Circle(rad);
	}
	
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2*Math.PI*this.radius;
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		return Math.PI*(java.lang.Math.pow(this.radius, 2));
	}
	
	public String getName() {
		return (this.getClass().getName()).toUpperCase();
	}
	
}
