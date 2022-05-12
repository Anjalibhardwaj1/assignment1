#include <stdio.h>
#include <stdlib.h>
//typedef enum when you know all possible types (like male/female, all different weekdays you would use typedef enum {MONDAY, TUESDAY...} weekdays
typedef enum { ATOM, LIST } eltype;
typedef char atom;
struct _listnode;
typedef struct {
	eltype type;
	union {
		atom a;
		struct _listnode* l; //l is a list
	};
} element;
typedef struct _listnode {
	element el;
	struct _listnode* next;
} *list;
const element NIL = { .type = LIST, .l = NULL };

element aasel(atom a) {
	//.type = ATOM converts the variableAtom element type, to type ATOM (from enum) and .a = a makes atom a = .a which is the paramter passed in the function
	//store the a value in the temporary varialbeAtom and return that to get whatever the atom a is
	element variableAtom = { .type = ATOM, .a = a }; 
	return variableAtom;
}

element lasel(list l) {
	element variableList = { .type = LIST, .l = l }; //same logic as aasel
	return variableList;
}

element car(element e) {
	if (e.type != LIST) { //if e is not type list, return NIL
		return NIL;
	}
	return e.l->el; //el is defacto head of any list as per the given struct _listnode
	//return *e.l.el;
	//l is the whole list
}

list cdr(element e) {
	if (e.type != LIST) { //if e is not type list, return NIL
		return NULL;
	}

	return e.l->next; //e.l points to next (from struct _listnode* next) which is like saying e.l points to the next element, which is like saying
	//e.l points to the tail since the next element is also linked to the rest of the list
}

list cddr(element e) {
	list temp = cdr(e);
	//return cdr(temp->el didn't work because temp->el is element of type atom and cdr requires the type to be LIST or else it returns NULL and therefore prints NIL
	return cdr(lasel(temp)); //creates a temp variable of type list to use the cdr function to get the tail of e,
	//returns the tail of cdr(e) which is the tail of the tail of e
}

list cons(element e, list l) {
	list newList;
	newList = malloc(sizeof(list));
	newList->el = e;
	newList->next = l;
	//variable newList of type list, allocate memory based on the size of list
	//newList->el = e means newList points to el (the head) = parameter e
	//newList->next = l means newList points to next (the tail) = paramter l

	return newList;
}

list append(list l1, list l2) {
	list firstList = l1;

	while (firstList->next != NULL) { //while loop to get to the last element of l1, stored as listOne
		firstList = firstList->next;
	}

	firstList->next = l2; //listOne, which is now at the last element of l1, points to next element which is l2, thus appending both lists together
	return l1; //doesn't work with return listOne?
}

void lfreer(list l) {
	list head = l;
	list temp;
	
	while (head != NULL) {
		temp = head->next; //stores the tail in temp
		free(head); //frees the memory of head
		head = temp; //makes head (which is basically our list) equal to temp, which was originally storing the tail of head so head is now its original tail
	}
}

void print(element e) {
	if (e.type == ATOM) {
		printf(" %c ", e.a); //simple printf for character with spaces
	}
	else if (e.type == LIST && e.l == NULL) {
		printf("NIL"); //self explanatory
	}
	else if (e.type == LIST) {
		list listElements = e.l;
		printf("(");
		while (listElements != NULL) { //while list element is not empty
			print(listElements->el); //print 'head' (el) element
			listElements = listElements->next; //list element is now at the next one, repeat until list element is empty
		}
		//IF there is a list element in the list, this while loop (recursively) prints each element of that list element surrounded by ()
		printf(")");
	}
}
//(a (b c) d)
//( a ( b  c )

int main() {
	element a = aasel('a'); //creates element a
	element b = aasel('b'); //creates element b
	element c = aasel('c'); //creates element c
	element d = aasel('d'); //creates element d
	element e = aasel('e'); //creates element e
	element f = aasel('f'); //creates element f

	list listA = malloc(sizeof(list)); //creates a list of single element a
	listA->el = a;
	listA->next = NULL;

	list listB = malloc(sizeof(list)); //creates a list of single element b
	listB->el = b;
	listB->next = NULL;

	list listC = malloc(sizeof(list)); //creates a list of single element c
	listC->el = c;
	listC->next = NULL;

	list listD = malloc(sizeof(list)); //creates a list of single element d
	listD->el = d;
	listD->next = NULL;

	list listE = malloc(sizeof(list)); //creates a list of single element e
	listE->el = e;
	listE->next = NULL;

	list listF = malloc(sizeof(list)); //creates a list of single element f
	listF->el = f; 
	listF->next = NULL;

	//list listG = malloc(sizeof(list));
	//listG->el = a;
	//listG->next = listE;

	//using cons to create a bunch of lists to test functions
	list listOne = cons(a, listB); //(a b)
	list listTwo = cons(b, listC); // (b c)
	list listThree = cons(e, listF); // (e f)
	list listFour = cons(c, listThree); // (c e f)
	list listFive = cons(a, listFour); // ( a c e f)



	print(lasel(listOne));
	printf("\n");
	print(lasel(append(listOne, listTwo)));
	printf("\n");
	print(lasel(listFour));
	printf("\n");
	print(lasel(listThree));
	printf("\n");
	print(lasel(listFour));
	printf("\n");
	print(lasel(listFive));
	printf("\n");
	print(lasel(append(listTwo, listFour))); //( b c c e f)
	printf("\n");
	print(car(lasel(listFour))); // c
	printf("\n");
	print(lasel(cdr(lasel(listThree)))); // ( f )
	printf("\n");
	print(lasel(cdr(lasel(listFour)))); // ( e f )
	printf("\n");
	print(lasel(cddr(lasel(listFive)))); // ( e f )
	
	return 0;
}